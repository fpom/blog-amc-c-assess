//let swap = 0
//let PARAM(x,y) = 'x, y'
//let comp = 'sum'
//let INIT = 0
//let PROCESS(c,v) = 'c += v'
//let NOT = 1
//let COND(f,c,v) = '!f'
//let FALSE = 0
//let TRUE = 1
//let join = 'sub'
//let FORALLIN = 'gyrated'
//let A = 'depute'
//let B = 'corneas'
//let C = 'discuss'
//let I = 'cellars'
//let J = 'alien'
//let F = 'plush'
//let U = 'charms'
//let TABU_LEN = 8
//let TABU_VAL = [4, 2, 4, 6, 4, 9, 4, 10]
//let TABU = '{.len=8, .val=malloc(8 * sizeof(int))}'
//let V = 'impels'
//let TABV_LEN = 6
//let TABV_VAL = [1, 2, 10, 4, 7, 8]
//let TABV = '{.len=6, .val=malloc(6 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int I;
  int C = INIT;
  int F;
  int J;
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
  Tab U = TABU;
  Tab V = TABV;
  U.val[0] = 4;
  U.val[1] = 2;
  U.val[2] = 4;
  U.val[3] = 6;
  U.val[4] = 4;
  U.val[5] = 9;
  U.val[6] = 4;
  U.val[7] = 10;
  V.val[0] = 1;
  V.val[1] = 2;
  V.val[2] = 10;
  V.val[3] = 4;
  V.val[4] = 7;
  V.val[5] = 8;
  printf("%i\n", FORALLIN(U, V));
  free(V.val);
  free(U.val);
}