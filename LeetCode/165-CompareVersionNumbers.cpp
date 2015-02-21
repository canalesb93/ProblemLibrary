/*
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

bool biggerString(string a, string b){
  bool aZero = false, bZero = false;
  for(int i = 0; i < a.size(); i++){
    if(a[i]!='0'){
      a = a.substr(i, a.size()-i);
      break;
    } else if(i == a.size()-1)
      aZero = true;
  }
  for(int i = 0; i < b.size(); i++){
    if(b[i]!='0'){
      b = b.substr(i, b.size()-i);
      break;
    }else if(i == b.size()-1)
      bZero = true;
  }
  if(bZero && aZero)
    return false;
  if(a.size() > b.size())
    return true;
  else if(b.size() > a.size())
    return false;
  else
    return a > b;
}

//10.22

void split(vector<string> &vec, string version){
  int counter = 0;
  for(int i = 0; i < version.size(); i++){
    if(version[i] == '.' || i == version.size()-1){
      if(i == version.size()-1)
        i++;
      vec.push_back(version.substr(counter, i-counter));
      counter = i+1;
    }
  }
}

int checkZeros(string s, int side){
  for(int j = 0; j < s.size(); j++){
    if(s[j] != '0')
      return side;
  }
  return 0;
}

int compareVersion(string version1, string version2) {
  vector<string> v1; 
  vector<string> v2;
  split(v1, version1);
  split(v2, version2);
  
  int largest;
  if(v1.size() > v2.size())
    largest = v1.size();
  else
    largest = v2.size();

  for(int i = 0; i < largest; i++){
    if(i > v1.size()-1){
      return checkZeros(v2[i], -1);
    } else if(i > v2.size()-1){
      return checkZeros(v1[i], 1);
    }

    if(biggerString(v1[i], v2[i])){
      return 1;
    }
    else if(biggerString(v2[i], v1[i]))
      return -1;
  }
  return 0;
}

int main ()
{

  cout <<compareVersion("1.1.01", "1.1") << endl;
  return 0;
}