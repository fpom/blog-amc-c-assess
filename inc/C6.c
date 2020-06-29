//let swap = 1
//let PARAM(x,y) = 'y, x'
//let comp = 'min'
//let INIT = 999
//let PROCESS(c,v) = 'c = v'
//let NOT = 0
//let COND(f,c,v) = 'f && (c > v)'
//let FALSE = 0
//let TRUE = 1
//let join = 'and'
//let FORALLIN = 'states'
//let A = 'atom'
//let B = 'insult'
//let C = 'linked'
//let I = 'itchier'
//let J = 'chassis'
//let F = 'bathe'
//let U = 'callow'
//let TABU_LEN = 10
//let TABU_VAL = [2, 10, 9, 8, 7, 1, 4, 7, 1, 1]
//let TABU = '{.len=10, .val=malloc(10 * sizeof(int))}'
//let V = 'quires'
//let TABV_LEN = 9
//let TABV_VAL = [7, 1, 8, 1, 5, 5, 7, 9, 6]
//let TABV = '{.len=9, .val=malloc(9 * sizeof(int))}'
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int len;
  int *val;
} Tab;

int FORALLIN (PARAM(Tab A,Tab B)) {
  int C = INIT;
  int I;
  int J;
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
  Tab U = TABU;
  Tab V = TABV;
  U.val[0] = 2;
  U.val[1] = 10;
  U.val[2] = 9;
  U.val[3] = 8;
  U.val[4] = 7;
  U.val[5] = 1;
  U.val[6] = 4;
  U.val[7] = 7;
  U.val[8] = 1;
  U.val[9] = 1;
  V.val[0] = 7;
  V.val[1] = 1;
  V.val[2] = 8;
  V.val[3] = 1;
  V.val[4] = 5;
  V.val[5] = 5;
  V.val[6] = 7;
  V.val[7] = 9;
  V.val[8] = 6;
  printf("%i\n", FORALLIN(U, V));
  free(V.val);
  free(U.val);
}