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

int countDigits(int x){
  int counter = 0;
  while(x != 0){
    x/=10;
    counter++;
  }
  return counter;
}

// 12021

bool isPalindrome(int x) {
  if(x<0)
    return false;
  int digitCount = countDigits(x);
  for(int i = 0; i < digitCount/2; i++){
    // cout << "left " << i << " = " << (x / (int)pow(10, digitCount - i -1)%10) << endl;
    // cout << "right " << i << " = " << (x % (int)pow(10, i+1)) / (int)pow(10, i) << endl;
    if((x / (int)pow(10, digitCount - i -1)%10) != (x % (int)pow(10, i+1)) / (int)pow(10, i)){
      return false;
    }
  }
  return true;
}

int main ()
{
  cout << countDigits(9999) << endl;
  cout << isPalindrome(9999) << endl;
  return 0;
}
