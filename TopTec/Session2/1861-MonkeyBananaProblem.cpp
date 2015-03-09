/*
1
4
7
6 4
2 5 10
9 8 12 2
2 12 7
8 2
10

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main ()
{
  int cases;
  cin >> cases;
  while(cases--){
    int N;
    cin >> N;
    int arr[N][N];
    int sums[N][N];
    for(int i = 0; i < N; i++){
      for(int j= 0; j < i + 1; j++){
        cin >> arr[i-j][j];
      }
    }
    for(int i = 0; i < N; i++){
      for(int j= N-1; j >= 1; j++){
        cin >> arr[i+1][j];
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
