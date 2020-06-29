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
//let FORALLIN = 'belie'
//let A = 'endue'
//let B = 'moodily'
//let C = 'jerkin'
//let I = 'accord'
//let J = 'inn'
//let F = 'nouns'
//let U = 'blamer'
//let TABU_LEN = 9
//let TABU_VAL = [1, 3, 7, 9, 9, 4, 6, 3, 5]
//let TABU = '{.len=9, .val=malloc(9 * sizeof(int))}'
//let V = 'clamps'
//let TABV_LEN = 8
//let TABV_VAL = [1, 2, 5, 10, 2, 9, 1, 2]
//let TABV = '{.len=8, .val=malloc(8 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int C = INIT;
  int F;
  int I;
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
  U.val[0] = 1;
  U.val[1] = 3;
  U.val[2] = 7;
  U.val[3] = 9;
  U.val[4] = 9;
  U.val[5] = 4;
  U.val[6] = 6;
  U.val[7] = 3;
  U.val[8] = 5;
  V.val[0] = 1;
  V.val[1] = 2;
  V.val[2] = 5;
  V.val[3] = 10;
  V.val[4] = 2;
  V.val[5] = 9;
  V.val[6] = 1;
  V.val[7] = 2;
  printf("%i\n", FORALLIN(U, V));
  free(U.val);
  free(V.val);
}