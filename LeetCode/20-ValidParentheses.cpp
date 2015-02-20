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

bool isValid(string s) {
  map<char, char> myMap;
  myMap[')'] = '(';
  myMap['}'] = '{';
  myMap[']'] = '[';
  stack<char> p;
  // ([{}])
  for(int i = 0; i < s.size(); i++){
    cout << "REACHED " << i << endl;
    if(s[i] == '(' || s[i] == '[' || s[i] == '{')
      p.push(s[i]);
    else {
      if(!p.empty() && myMap[s[i]] == p.top())
        p.pop();
      else
        return false;
    }
  }
  if(!p.empty())
    return false;
  return true;
}

int main (){
  cout << isValid("()[]{}}") << endl;

  return 0;
}

