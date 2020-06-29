//let swap = 1
//let PARAM(x,y) = 'y, x'
//let comp = 'max'
//let INIT = 0
//let PROCESS(c,v) = 'c = v'
//let NOT = 1
//let COND(f,c,v) = '(!f) && (v > c)'
//let FALSE = 0
//let TRUE = 1
//let join = 'sub'
//let FORALLIN = 'junkie'
//let A = 'news'
//let B = 'dislike'
//let C = 'undo'
//let I = 'abode'
//let J = 'severer'
//let F = 'dizzy'
//let U = 'skimpy'
//let TABU_LEN = 5
//let TABU_VAL = [7, 7, 7, 2, 1]
//let TABU = '{.len=5, .val=malloc(5 * sizeof(int))}'
//let V = 'nickels'
//let TABV_LEN = 8
//let TABV_VAL = [9, 1, 3, 8, 5, 1, 7, 8]
//let TABV = '{.len=8, .val=malloc(8 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int J;
  int C = INIT;
  int F;
  int I;
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

int main () {
  Tab V = TABV;
  Tab U = TABU;
  U.val[0] = 7;
  U.val[1] = 7;
  U.val[2] = 7;
  U.val[3] = 2;
  U.val[4] = 1;
  V.val[0] = 9;
  V.val[1] = 1;
  V.val[2] = 3;
  V.val[3] = 8;
  V.val[4] = 5;
  V.val[5] = 1;
  V.val[6] = 7;
  V.val[7] = 8;
  printf("%i\n", FORALLIN(U, V));
  free(U.val);
  free(V.val);
}