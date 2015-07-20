/*
Hello World!
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

void rowAndColtoZero(int matrix[][4], int n){
  map<int, bool> rows, cols;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(matrix[i][j] == 0){
        rows[i] = true;
        cols[j] = true;
      }
    }
  }

  for (map<int,bool>::iterator it=rows.begin(); it!=rows.end(); ++it){
    for(int j = 0; j < n; j++){
      matrix[it->first][j] = 0;
    }
  }

  for (map<int,bool>::iterator it=cols.begin(); it!=cols.end(); ++it){
    for(int j = 0; j < n; j++){
      matrix[j][it->first] = 0;
    }
  }

  // for(int i = 0; i < rows.size(); i++){
  // }

  // for(int i = 0; i < cols.size(); i++){
  //   for(int j = 0; j < n; j++){
  //     matrix[j][cols[i]] = 0;
  //   }
  // }

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
  matrix[3][3] = 0;
  matrix[1][1] = 0;

  printMatrix(matrix);
  printf("\n");
  rowAndColtoZero(matrix, 4);
  printMatrix(matrix);


  

  return 0;
}
 