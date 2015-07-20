/*
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <fstream>
 
using namespace std;

void rotateMatrix(int matrix[][4], int n){

  for(int layer = 0; layer < n/2; layer++){
    int first = layer, last = n - 1 - layer;

    for(int i = first; i < last; i++){
      int offset = i - first;


      int temp = matrix[first][i];
      // left -> top
      matrix[first][i] = matrix[last - offset][first];

      // bottom -> left
      matrix[last-offset][first] = matrix[last][last-offset];

      // right -> bottom
      matrix[last][last-offset] = matrix[i][last];

      // top -> right
      matrix[i][last] = temp;
    }

  }

}

void printMatrix(int matrix[][4]){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main ()
{
  int matrix[4][4];
  int count = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      matrix[i][j] = count;
      count++;
    }
  }

  printMatrix(matrix);
  printf("\n");
  rotateMatrix(matrix, 4);
  printMatrix(matrix);


  return 0;
}
 