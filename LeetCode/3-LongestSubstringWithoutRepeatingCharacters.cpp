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

int lengthOfLongestSubstring(string s) {
  map<char, int> m;
  int maxLen = 0;
  int lastRepeatPos = -1;
  for(int i=0; i<s.size(); i++){
    if (m.find(s[i])!=m.end() && lastRepeatPos < m[s[i]]) {
        lastRepeatPos = m[s[i]];
    }
    if ( i - lastRepeatPos > maxLen ){
        maxLen = i - lastRepeatPos;
    }
    m[s[i]] = i;
  }
  return maxLen;
}

int main ()
{
  //                                01234567
  cout << lengthOfLongestSubstring("testerpo") << endl;
  return 0;
}
