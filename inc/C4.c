//let swap = 1
//let PARAM(x,y) = 'y, x'
//let comp = 'sum'
//let INIT = 0
//let PROCESS(c,v) = 'c += v'
//let NOT = 1
//let COND(f,c,v) = '!f'
//let FALSE = 1
//let TRUE = 0
//let join = 'and'
//let FORALLIN = 'sired'
//let A = 'same'
//let B = 'phlox'
//let C = 'hauls'
//let I = 'meaner'
//let J = 'clawed'
//let F = 'wattle'
//let U = 'scruffy'
//let TABU_LEN = 10
//let TABU_VAL = [8, 7, 5, 9, 6, 5, 5, 3, 8, 1]
//let TABU = '{.len=10, .val=malloc(10 * sizeof(int))}'
//let V = 'fiddly'
//let TABV_LEN = 10
//let TABV_VAL = [4, 10, 1, 3, 8, 9, 8, 7, 4, 10]
//let TABV = '{.len=10, .val=malloc(10 * sizeof(int))}'
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
  U.val[0] = 8;
  U.val[1] = 7;
  U.val[2] = 5;
  U.val[3] = 9;
  U.val[4] = 6;
  U.val[5] = 5;
  U.val[6] = 5;
  U.val[7] = 3;
  U.val[8] = 8;
  U.val[9] = 1;
  V.val[0] = 4;
  V.val[1] = 10;
  V.val[2] = 1;
  V.val[3] = 3;
  V.val[4] = 8;
  V.val[5] = 9;
  V.val[6] = 8;
  V.val[7] = 7;
  V.val[8] = 4;
  V.val[9] = 10;
  printf("%i\n", FORALLIN(U, V));
  free(U.val);
  free(V.val);
}