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
    


    // ZA
string convertToTitle(int n) {
  string answer = "";
  while(n > 0){
    n = n - 1;
    answer = (char)(((n)%26) + 'A') + answer;
    n /= 26;
  }
  
  return answer;
}

int main ()
{
  cout << convertToTitle(23) << endl;
  return 0;
}
