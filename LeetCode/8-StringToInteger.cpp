/*
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int atoi(string str) {
  if (str.size() <= 0){
    return 0;
  }
  
  int originalSize = 0, power = 0, counter=0;
  int answer = 0;
  originalSize = str.size();

  for(;isspace(str[counter]); counter++);

  bool negative = false;
  if (str[counter]=='-' || str[counter]=='+') {
      negative = (str[counter]=='-') ;
      counter++;
  }

  int ret = 0;
  for(;isdigit(str[counter]);counter++){
    int digit = str[counter] - '0';
    if(negative){
      if( -ret < (INT_MIN + digit)/10 ) {
        return INT_MIN;
      }
    } else if( ret > (INT_MAX - digit) /10 ) {
      return INT_MAX;
    }

    ret = 10*ret + digit;
  }

  if(negative)
    ret *= -1;

  return ret;
}

int main (){
  printf("\"%s\" = %d\n", "123", atoi("123"));
  printf("\"%s\" = %d\n", "   123", atoi("    123"));
  printf("\"%s\" = %d\n", "+123", atoi("+123"));
  printf("\"%s\" = %d\n", " -123", atoi(" -123"));
  printf("\"%s\" = %d\n", "123ABC", atoi("123ABC"));
  printf("\"%s\" = %d\n", " abc123ABC", atoi(" abc123ABC"));
  printf("\"%s\" = %d\n", "2147483647", atoi("2147483647"));
  printf("\"%s\" = %d\n", "-2147483648", atoi("-2147483648"));
  printf("\"%s\" = %d\n", "2147483648", atoi("2147483648"));
  printf("\"%s\" = %d\n", "-2147483651", atoi("-2147483651"));

  return 0;
}

//2147483647