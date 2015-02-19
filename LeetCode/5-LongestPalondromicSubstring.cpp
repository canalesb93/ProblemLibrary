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

string findPalindrome(string s, int left, int right){
    int n = s.size();
    int l = left;
    int r = right;
    while (left>=0 && right<=n-1 && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}

string longestPalindrome(string s) {
  int n = s.size();
  string longest;

  for(int i = 0; i < n; i++){
    string aux;
    aux = findPalindrome(s, i, i);
    if(aux.size() > longest.size()){
      longest = aux;
    }
    aux = findPalindrome(s, i, i+1);
    if(aux.size() > longest.size()){
      longest = aux;
    }
  }
  return longest;
}

int main ()
{

  cout << longestPalindrome("tettesset") << endl;
  return 0;
}
