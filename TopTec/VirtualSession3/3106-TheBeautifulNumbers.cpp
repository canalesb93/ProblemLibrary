/*
11 411
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

bool isPalindrome(string myString){
  int length = myString.size();
  int middle = length/2, even = 0;
  int start = 0;

  if(length%2==0) even = 1;

  for(int i = 1; i <= middle; i++ ){
    if(myString[middle + i - even] != myString[middle - i])
      return false;
  }
  return true;
}

// 123321

int main ()
{
  string num1, num2;
  cin >> num1 >> num2;

  if(isPalindrome(num1 + num2))
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
