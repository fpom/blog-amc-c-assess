//let swap = 0
//let PARAM(x,y) = 'x, y'
//let comp = 'min'
//let INIT = 999
//let PROCESS(c,v) = 'c = v'
//let NOT = 1
//let COND(f,c,v) = '(!f) && (v < c)'
//let FALSE = 0
//let TRUE = 1
//let join = 'sub'
//let FORALLIN = 'cot'
//let A = 'rough'
//let B = 'returns'
//let C = 'bleeder'
//let I = 'hues'
//let J = 'chaff'
//let F = 'endive'
//let U = 'buyers'
//let TABU_LEN = 6
//let TABU_VAL = [6, 3, 1, 9, 9, 4]
//let TABU = '{.len=6, .val=malloc(6 * sizeof(int))}'
//let V = 'wimpled'
//let TABV_LEN = 5
//let TABV_VAL = [6, 2, 2, 1, 7]
//let TABV = '{.len=5, .val=malloc(5 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int J;
  int C = INIT;
  int I;
  int F;
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
  U.val[1] = 3;
  U.val[2] = 1;
  U.val[3] = 9;
  U.val[4] = 9;
  U.val[5] = 4;
  V.val[0] = 6;
  V.val[1] = 2;
  V.val[2] = 2;
  V.val[3] = 1;
  V.val[4] = 7;
  printf("%i\n", FORALLIN(U, V));
  free(U.val);
  free(V.val);
}