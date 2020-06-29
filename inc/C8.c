//let swap = 0
//let PARAM(x,y) = 'x, y'
//let comp = 'min'
//let INIT = 999
//let PROCESS(c,v) = 'c = v'
//let NOT = 1
//let COND(f,c,v) = '(!f) && (c > v)'
//let FALSE = 1
//let TRUE = 0
//let join = 'and'
//let FORALLIN = 'magic'
//let A = 'slaw'
//let B = 'creeks'
//let C = 'lighten'
//let I = 'agonize'
//let J = 'gable'
//let F = 'shack'
//let U = 'jesting'
//let TABU_LEN = 10
//let TABU_VAL = [4, 5, 2, 2, 8, 3, 5, 10, 2, 1]
//let TABU = '{.len=10, .val=malloc(10 * sizeof(int))}'
//let V = 'renders'
//let TABV_LEN = 7
//let TABV_VAL = [6, 8, 4, 3, 7, 7, 5]
//let TABV = '{.len=7, .val=malloc(7 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int J;
  int F;
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
  U.val[0] = 4;
  U.val[1] = 5;
  U.val[2] = 2;
  U.val[3] = 2;
  U.val[4] = 8;
  U.val[5] = 3;
  U.val[6] = 5;
  U.val[7] = 10;
  U.val[8] = 2;
  U.val[9] = 1;
  V.val[0] = 6;
  V.val[1] = 8;
  V.val[2] = 4;
  V.val[3] = 3;
  V.val[4] = 7;
  V.val[5] = 7;
  V.val[6] = 5;
  printf("%i\n", FORALLIN(U, V));
  free(U.val);
  free(V.val);
}