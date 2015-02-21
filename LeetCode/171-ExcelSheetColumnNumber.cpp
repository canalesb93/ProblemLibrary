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

// A = 0 * 26^1   C = 0 * 26^0

using namespace std;

int titleToNumber(string s) {
  int answer = 0, size = s.size() - 1;
  for(int i = 0; i < s.size(); i++){
    
    answer += ((s[i] - 'A') + 1) * pow(26, size--);
  }
  return answer;
}

int main ()
{
  cout << titleToNumber("ZZ")<< endl;  
  return 0;
}
