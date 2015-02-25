/*
27 12
2460000 98400
3 4000
0 0
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>


using namespace std;

int main ()
{
  long n, m, whole;
  scanf("%ld %ld", &n, &m);
  while(n || m){
    whole = n / m;
    while(n >= m)
      n -= m; 

    printf("%ld %ld / %ld\n", whole, n, m);
    scanf("%ld %ld", &n, &m);
  }
  
  return 0;
}
