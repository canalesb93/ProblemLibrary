/*
HelloWorld!
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <fstream>

#define INF 2147483646
 
using namespace std;

string shortestSubstringWithCharacters(vector<char> chars, string str){
  int left = 0, right = 0, rLeft, rRight;
  int subsize = INF;
  bool allFound = false;

  map<char, bool> exist;
  map<char, int> positions; // only containes original chars

  // maps original chars to easily know they exist
  for(int i = 0; i < chars.size(); i++){
    exist[chars[i]] = true;
  }

  //start iterating
  while(right < str.size()){
    if(exist[str[right]]){
      positions[str[right]] = right;
      if(positions.size() == chars.size()) allFound = true;
    }
    if(str[right] == str[left]){
        while(left != positions[str[left]]) left++;
    }
    if(allFound){
      if((right - left +1) < subsize){
        subsize = (right - left +1);
        rLeft = left;
        rRight = right;
      }
    }
    right++;
  }

  if(!allFound) return ""; // no substring;
  return str.substr(rLeft, subsize);
}

int main() {
    string input;
    cin >> input;
    vector<char> chars;
    chars.push_back('x');
    chars.push_back('y');
    chars.push_back('z');
    
//                                                  01234567
    cout << shortestSubstringWithCharacters(chars, "xyyzzzyx") << endl;
    return 0;
}