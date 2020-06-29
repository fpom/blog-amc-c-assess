import tempfile, subprocess, pathlib, random
import badass.p5 as p5

class Exo (p5.PrePreProcessor) :
    def __init__ (self, path="algo.c") :
        super().__init__(path)
        self.swap = self.top.cppenv["swap"]
        self.join = self.top.cppenv["join"]
        self.comp = self.top.cppenv["comp"]
    def run (self) :
        with tempfile.NamedTemporaryFile(mode="w", encoding="utf-8", suffix=".c") as tmp :
            tmp.write(self.cpp)
            tmp.flush()
            subprocess.check_output(["gcc", tmp.name])
        return subprocess.run(["./a.out"],
                              capture_output=True,
                              encoding="utf-8").stdout.strip()
    def algos (self, tex=False) :
        _comp = {"min" : "the smallest value that is",
                 "max" : "the largest value that is",
                 "sum" : "the sum of the values that are",
                 "num" : "the number of values that are"}
        _join = {"sub" : "in {X} but not in {Y}",
                 "and" : "both in {X} and in {Y}"}
        for swap in (0, 1) :
            X, Y = self.top.cppenv["A"], self.top.cppenv["B"]
            if swap :
                X, Y = Y, X
            if tex :
                X = fr"\texttt{{{X}}}"
                Y = fr"\texttt{{{Y}}}"
            for join in ("sub", "and") :
                for comp in ("min", "max", "sum", "num") :
                    where = _join[join].format(X=X, Y=Y)
                    good = (swap, join, comp) == (self.swap, self.join, self.comp)
                    value = self.compute(swap, join, comp)
                    if good :
                        assert int(self.run()) == value, "inconsistent value"
                    yield good, value, f"{_comp[comp]} {where}"
    def compute (self, swap, join, comp) :
        U, V = self.top.cppenv["TABU_VAL"], self.top.cppenv["TABV_VAL"]
        if swap :
            U, V = V, U
        if join == "and" :
            T = [u for u in U if u in V]
        elif join == "sub" :
            T = [u for u in U if u not in V]
        else :
            assert False, "unexpected case"
        if comp == "min" :
            return min(T, default=999)
        elif comp == "max" :
            return max(T, default=0)
        elif comp == "sum" :
            return sum(T, 0)
        elif comp == "num" :
            return len(T)
        else :
            assert False, "unexpected case"
    def png (self, path, cols=1, **args) :
        args.setdefault("font_size", 24)
        args.setdefault("line_pad", 8)
        args.setdefault("stripnl", False)
        base = pathlib.Path(path).with_suffix("")
        lines = self.cpp.splitlines()
        if len(lines) % cols :
            lines.extend([""] * (cols - (len(lines) % cols)))
        assert len(lines) % cols == 0
        chunk = len(lines) // cols
        for c in range(cols) :
            with tempfile.NamedTemporaryFile(mode="w", suffix=".c") as tmp :
                tmp.write("\n".join(lines[c*chunk:(c+1)*chunk]))
                tmp.write("\n")
                tmp.flush()
                args["line_number_start"] = c*chunk + 1
                subprocess.check_call(["pygmentize",
                                       "-l", "C",
                                       "-f", "png",
                                       "-O", ",".join(f"{k}={v}"
                                                      for k, v in args.items()),
                                       "-o", f"{base}-{c}.png",
                                       tmp.name])
        subprocess.check_call(["convert"]
                              + [f"{base}-{c}.png" for c in range(cols)]
                              + ["+append", f"{base}.png"])
        for c in range(cols) :
            pathlib.Path(f"{base}-{c}.png").unlink()
    def tex (self, num, out) :
        for key, val in self.top.cppenv.items() :
            out.write(fr"\expandafter\def\csname cpp:{key}\endcsname{{{val}}}" "\n")
        out.write("\n" r"\def\C#1{\csname cpp:#1\endcsname}" "\n\n"
                  fr"\element{{COMP{num}}}{{" "\n"
                  r"  \begin{questionmult}{C1}" "\n"
                  r"    What does function \C{FORALLIN} computes?" "\n"
                  r"    \AMCBoxedAnswers" "\n"
                  r"    \begin{reponses}" "\n")
        values, result = set(), None
        for good, val, txt in self.algos(tex=True) :
            values.add(val)
            if good :
                result = val
                out.write(fr"      \correctchoice{{{txt}}}" "\n")
            else :
                out.write(fr"      \wrongchoice{{{txt}}}" "\n")
        out.write(r"    \end{reponses}" "\n"
                  r"  \end{questionmult}" "\n"
                  r"  \begin{questionmult}{C2}" "\n"
                  r"    What does the program prints?" "\n"
                  r"    \begin{multicols}{4}" "\n"
                  r"      \AMCBoxedAnswers" "\n"
                  r"      \begin{reponses}" "\n")
        values.update(random.sample(range(30), 5))
        for val in values :
            if val == result :
                out.write(fr"        \correctchoice{{{val}}}" "\n")
            else :
                out.write(fr"        \wrongchoice{{{val}}}" "\n")
        out.write(r"      \end{reponses}" "\n"
                  r"    \end{multicols}" "\n"
                  r"  \end{questionmult}" "\n"
                  r"  \begin{questionmult}{C3}" "\n"
                  r"    What does the program prints?" "\n"
                  fr"    \AMCnumericChoices{{{result}}}{{digits=3,vertical=true,"
                  r"scoreexact=1,scoreapprox=0,borderwidth=1pt,sign=false}" "\n"
                  r"  \end{questionmult}" "\n"
                  r"}" "\n\n")

if __name__ == "__main__" :
    import tqdm
    inc = pathlib.Path("../inc")
    inc.mkdir(exist_ok=True)
    for num in tqdm.tqdm(range(1, 11)) :
        e = Exo()
        with open(inc / f"C{num}.tex", "w") as out :
            e.tex(num, out)
        with open(inc / f"C{num}.c", "w") as out :
            e.save(out)
        e.png(inc / f"C{num}.png", 2)
