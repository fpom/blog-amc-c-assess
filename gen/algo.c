//let swap = randint(0, 1)
//if swap
  //let PARAM(x,y) = "y, x"
//else
  //let PARAM(x,y) = "x, y"
//end if
//let comp = choice("min", "max", "sum", "num")
//if comp == "min"
  //let INIT = 999
  //let PROCESS(c,v) = "c = v"
//else if comp == "max"
  //let INIT = 0
  //let PROCESS(c,v) = "c = v"
//else if comp == "sum"
  //let INIT = 0
  //let PROCESS(c,v) = "c += v"
//else if comp == "num"
  //let PROCESS(c,v) = "c++"
  //let INIT = 0
//end if
//let NOT = randint(0, 1)
//if NOT
  //if comp == "min"
    //let COND(f,c,v) = choice("(!f) && (v < c)", "(!f) && (c > v)", "(v < c) && (!f)", "(c > v) && (!f)")
  //else if comp == "max"
    //let COND(f,c,v) = choice("(!f) && (c < v)", "(!f) && (v > c)", "(c < v) && (!f)", "(v > c) && (!f)")
  //else
    //let COND(f,c,v) = "!f"
  //end if
//else
  //if comp == "min"
    //let COND(f,c,v) = choice("f && (v < c)", "f && (c > v)", "(v < c) && f", "(c > v) && f")
  //else if comp == "max"
    //let COND(f,c,v) = choice("f && (c < v)", "f && (v > c)", "(c < v) && f", "(v > c) && f")
  //else
    //let COND(f,c,v) = "f"
  //end if
//end if
//let FALSE = randint(0, 1)
//let TRUE = 1 - FALSE
//let join = "sub" if FALSE ^ NOT else "and"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

//let FORALLIN = randname()
//let A = randname()
//let B = randname()
//let C = randname()
//let I = randname()
//let J = randname()
//let F = randname()
int FORALLIN (PARAM(Tab A,Tab B)) {
  //shuffle
  int C = INIT;
  int I;
  int J;
  int F;
  //end shuffle
  for (I=0; I<A.len; I++) {
    F = FALSE;
    for (J=0; J<B.len; J++) {
      if (A.val[I] == B.val[J]) {
        F = TRUE;
        break;
      }
    }
    if (COND(F,C,A.val[I])) {
      PROCESS(C,A.val[I]);
    }
  }
  return C;
}

//let U = randname()
//let TABU_LEN = randint(5, 10)
//let TABU_VAL = randint(1, 10, len=TABU_LEN, fmt=None)
//let TABU = f"{{.len={TABU_LEN}, .val=malloc({TABU_LEN} * sizeof(int))}}"
//let V = randname()
//let TABV_LEN = randint(5, 10)
//let TABV_VAL = randint(1, 10, len=TABV_LEN, fmt=None)
//let TABV = f"{{.len={TABV_LEN}, .val=malloc({TABV_LEN} * sizeof(int))}}"
int main () {
  //shuffle
  Tab U = TABU;
  Tab V = TABV;
  //end shuffle
  //for IDX, VAL in enumerate(TABU_VAL)
  U.val[IDX] = VAL;
  //end for
  //for IDX, VAL in enumerate(TABV_VAL)
  V.val[IDX] = VAL;
  //end for
  printf("%i\n", FORALLIN(U, V));
  //shuffle
  free(U.val);
  free(V.val);
  //end shuffle
}
