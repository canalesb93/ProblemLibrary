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
  int max = 0, last_repeat = -1;

  for(int i = 0; i < s.length(); i++){

    if(m.find(s[i]) != m.end() && last_repeat < m[s[i]]){
      last_repeat = m[s[i]];
    }
    m[s[i]] = i;
    if(i - last_repeat > max) max = i - last_repeat;
  }
  return max;
}

int main ()
{
  //                                01234567
  cout << lengthOfLongestSubstring("c") << endl;
  return 0;
}
