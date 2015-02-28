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
#include <utility>
#include <stdio.h>
#include <ctype.h>

using namespace std;

// applepie
// applecake

string longestCommonPrefix(vector<string> &strs) {
  int arraySize = strs.size();
  if(arraySize == 0)
    return "";
  vector<int> sizes(arraySize, 0);
  for(int i = 0; i < arraySize; i++){
    sizes[i] = strs[i].size();
  }
  int pointer = 0;
  string prefix = "";
  char currentChar;
  while(true){
    // printf("%d\n", pointer);
    if(pointer < sizes[0])
      currentChar = strs[0][pointer];
    else
      break;
    bool passed = true;
    for(int i = 1; i < arraySize; i++){
      if(pointer > sizes[i] || currentChar != strs[i][pointer]){
        passed = false;
        break;
      }
    }
    if(passed == false){
      break;
    } else {
      prefix += currentChar;
    }
    pointer++;
  }
  return prefix;
}

int main ()
{
  vector<string> strs;
  strs.push_back("apple");
  strs.push_back("apple");
  strs.push_back("apple");
  strs.push_back("apple");

  cout << longestCommonPrefix(strs) << endl;


  return 0;
}
