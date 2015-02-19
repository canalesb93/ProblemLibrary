/*
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
#include <ctype.h>

using namespace std;

// #define INT_MAX 2147483647
// #define INT_MIN (-2147483647 - 1)
//321

int reverse(int x) {
  int last = 0, newInt = 0;

  while(x!=0){
    last = x%10;
    if(newInt > INT_MAX/10 || newInt < INT_MIN/10)
      return 0;
    newInt = newInt * 10 + last;
    x /= 10;
  }
  return newInt;
      
}

int main ()
{

  cout << reverse(1534236469) << endl;
  return 0;
}
