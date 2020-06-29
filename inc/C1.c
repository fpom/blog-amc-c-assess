//let swap = 1
//let PARAM(x,y) = 'y, x'
//let comp = 'sum'
//let INIT = 0
//let PROCESS(c,v) = 'c += v'
//let NOT = 1
//let COND(f,c,v) = '!f'
//let FALSE = 0
//let TRUE = 1
//let join = 'sub'
//let FORALLIN = 'highest'
//let A = 'piecing'
//let B = 'lazied'
//let C = 'vast'
//let I = 'sibyls'
//let J = 'cooky'
//let F = 'bifocal'
//let U = 'getup'
//let TABU_LEN = 10
//let TABU_VAL = [7, 3, 1, 7, 8, 6, 10, 2, 4, 3]
//let TABU = '{.len=10, .val=malloc(10 * sizeof(int))}'
//let V = 'cupful'
//let TABV_LEN = 8
//let TABV_VAL = [3, 3, 4, 4, 8, 9, 2, 3]
//let TABV = '{.len=8, .val=malloc(8 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int J;
  int F;
  int I;
  int C = INIT;
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
  U.val[1] = 3;
  U.val[2] = 1;
  U.val[3] = 7;
  U.val[4] = 8;
  U.val[5] = 6;
  U.val[6] = 10;
  U.val[7] = 2;
  U.val[8] = 4;
  U.val[9] = 3;
  V.val[0] = 3;
  V.val[1] = 3;
  V.val[2] = 4;
  V.val[3] = 4;
  V.val[4] = 8;
  V.val[5] = 9;
  V.val[6] = 2;
  V.val[7] = 3;
  printf("%i\n", FORALLIN(U, V));
  free(V.val);
  free(U.val);
}