/*
Hello World!
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


// XIV

int romanToInt(string s) {
  map<char, int> romans;
  romans['I']= 1;
  romans['V']= 5;
  romans['X']= 10;
  romans['L']= 50;
  romans['C']= 100;
  romans['D']= 500;
  romans['M']= 1000;

  int sum = 0, before = 0;
  for(int i = s.size()-1; i >= 0; i--){
    if(romans[s[i]] < before)
      sum -= romans[s[i]];
    else
      sum += romans[s[i]];
    before = romans[s[i]];
  }
  return sum;
}

int main ()
{

  cout << romanToInt("XIV") << endl;  
  return 0;
}
