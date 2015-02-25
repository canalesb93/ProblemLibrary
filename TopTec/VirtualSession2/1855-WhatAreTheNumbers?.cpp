/*
2
5
1
2
3
2
2
2
12313
564848
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>


using namespace std;

int main ()
{ 
  int t, n;
  scanf("%i", &t);
  while(t--){
    scanf("%i", &n);
    map<long long, int> nums; // 1= discovered, 2= repeated
    bool repeated = false;
    while(n--){
      long long num;
      scanf("%lli", &num);
      int *pointer = &nums[num];
      if(*pointer == 0){
        *pointer = 1;
      } else if(*pointer == 1){
        repeated = true;
        printf("%lli\n", num);
      }
    }
    if(!repeated)
      printf("Not found!\n");
  }


  return 0;
}
