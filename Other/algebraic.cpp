/*
3
1
2
2171
*/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main(){
  long long int MODULO = 1000000007;
  int cases;
  cin >> cases;
  while(cases--){
    long long int ans = 1LL % MODULO;
  
    int set_size;
    cin >> set_size;
  
    for(int i = 2; i <= set_size; i++) {
      ans = ((i % MODULO) * (ans % MODULO)) % MODULO;
    }
    printf("%lld\n", ans - 1);
  }
  return 0;
}