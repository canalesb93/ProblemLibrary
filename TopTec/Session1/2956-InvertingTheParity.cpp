/*
5
10
7
99
16
9
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

int T;
int N;

int main ()
{
  scanf ("%d",&T);
  for(int i = 0; i < T; i++){
    scanf ("%d",&N);
    if(N%2 == 1){
      N = N*2;
    } else{
      while(N%2 == 0)
        N/=2;
    }
    printf("%d\n", N);
  }
  return 0;
}
