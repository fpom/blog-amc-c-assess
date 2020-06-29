//let swap = 1
//let PARAM(x,y) = 'y, x'
//let comp = 'num'
//let PROCESS(c,v) = 'c++'
//let INIT = 0
//let NOT = 0
//let COND(f,c,v) = 'f'
//let FALSE = 0
//let TRUE = 1
//let join = 'and'
//let FORALLIN = 'licked'
//let A = 'posh'
//let B = 'buggier'
//let C = 'malts'
//let I = 'legal'
//let J = 'alibied'
//let F = 'outpost'
//let U = 'profuse'
//let TABU_LEN = 5
//let TABU_VAL = [4, 6, 10, 1, 10]
//let TABU = '{.len=5, .val=malloc(5 * sizeof(int))}'
//let V = 'navels'
//let TABV_LEN = 10
//let TABV_VAL = [4, 7, 1, 3, 8, 5, 5, 10, 1, 2]
//let TABV = '{.len=10, .val=malloc(10 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int C = INIT;
  int F;
  int J;
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
  U.val[1] = 6;
  U.val[2] = 10;
  U.val[3] = 1;
  U.val[4] = 10;
  V.val[0] = 4;
  V.val[1] = 7;
  V.val[2] = 1;
  V.val[3] = 3;
  V.val[4] = 8;
  V.val[5] = 5;
  V.val[6] = 5;
  V.val[7] = 10;
  V.val[8] = 1;
  V.val[9] = 2;
  printf("%i\n", FORALLIN(U, V));
  free(U.val);
  free(V.val);
}