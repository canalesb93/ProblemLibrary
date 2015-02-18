/*
1
5
2
5 4
3
5 5 4
0
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

long long N;

int main ()
{
  cin >> N;
  double vec[100001];
  while(N!=0){
    for(long long i = 0; i < N; i++){
      cin >> vec[i];
    }
    sort(vec, vec + N);
    
    double floatValue;

    if(N%2 == 0){
      // cout << vec[N/2] << " - " << vec[(N/2)+1] << endl;
      long long x = ((N-1)/2);
      long long y = (N/2);
      floatValue = (vec[x]+vec[y])/2.0;
    } else {
      floatValue = vec[(N-1)/2];
    }
    printf("%.1f\n", floatValue);
    cin >> N;
  }


  return 0;
}
