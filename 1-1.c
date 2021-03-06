#include <stdio.h>
#include <stdlib.h>

int maxBlock(int** z, int m, int n) {
  int max = 0;
  int i,j;
  int k,l;
  int inBox = 0;
  
  for(i = 0; i < m ; i++) {
    for(j = 0; j < n; j++) {
      if(z[i][j] == 1) {
        max = 1;
        for(k=j; k < n ; k++) {
            if(z[i][j] == 1) {
              inBox++;
            }
            else {
              break;
            }
        }
          
        if(inBox == 1) {
          if(max < inBox) {
            max = inBox;
          }
        }
        
        if(inBox != 1 && inBox != 0) {
          int to = k + inBox;
          for(k = j ; k < to; k++) {
            for(l = i; l < to; l++) {
              if(z[k][l]!=1) {
                if(k - i == l - j) {
                  max = k - i - 1;
                }
                if(k - i < l - j) {
                  max = k - i;
                }
                else {
                  max = l - j;
                }
                break;
              }
            }
          }
        }
      }
    }
  }  
  return max;
}

int main () {
  int matrix[5][6] = {
    {0,1,0,1,0,0},
    {0,1,1,1,1,0},
    {0,1,1,1,1,0},
    {0,0,1,1,1,1},
    {1,0,0,1,0,1}
    }; 
  
  printf("%d\n", maxBlock(matrix, 5, 6)); 
  return 0;
}
