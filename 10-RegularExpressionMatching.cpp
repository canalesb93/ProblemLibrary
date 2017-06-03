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
 
using namespace std;

bool matches(string s, string p, int pattern_p, int input_p){
  if(pattern_p == p.length()) return input_p == s.length();

  if(p[pattern_p+1] != '*'){
    if(p[pattern_p] == s[input_p] || p[pattern_p] == '.')    
      return matches(s, p, pattern_p+1, input_p+1);
    return false;
  } else {
    if(matches(s, p, pattern_p + 2, input_p)) return true;
    while(input_p < s.size() && (s[input_p] == p[pattern_p] || p[pattern_p] == '.')){
      if(matches(s, p, pattern_p+2, ++input_p)) return true;
    }
    return false;
  }

}

bool isMatch(string s, string p) {
  return matches(s, p, 0, 0);
}

int main() {
    string input;
    cin >> input;

    cout << isMatch("ab", "ab*b") << endl;

    return 0;

}