//let swap = 1
//let PARAM(x,y) = 'y, x'
//let comp = 'max'
//let INIT = 0
//let PROCESS(c,v) = 'c = v'
//let NOT = 0
//let COND(f,c,v) = '(v > c) && f'
//let FALSE = 0
//let TRUE = 1
//let join = 'and'
//let FORALLIN = 'roar'
//let A = 'gerbil'
//let B = 'filmed'
//let C = 'franc'
//let I = 'colors'
//let J = 'bathing'
//let F = 'side'
//let U = 'wood'
//let TABU_LEN = 6
//let TABU_VAL = [6, 7, 7, 10, 1, 5]
//let TABU = '{.len=6, .val=malloc(6 * sizeof(int))}'
//let V = 'maces'
//let TABV_LEN = 6
//let TABV_VAL = [5, 1, 2, 1, 7, 1]
//let TABV = '{.len=6, .val=malloc(6 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int F;
  int J;
  int C = INIT;
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
  U.val[0] = 6;
  U.val[1] = 7;
  U.val[2] = 7;
  U.val[3] = 10;
  U.val[4] = 1;
  U.val[5] = 5;
  V.val[0] = 5;
  V.val[1] = 1;
  V.val[2] = 2;
  V.val[3] = 1;
  V.val[4] = 7;
  V.val[5] = 1;
  printf("%i\n", FORALLIN(U, V));
  free(V.val);
  free(U.val);
}