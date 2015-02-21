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

int majorityElement(vector<int> &num) {
  int majorElement;
  map<int, int> m;
  for(int i = 0; i < num.size(); i++){
    if(m.find(num[i]) == m.end())
      m[num[i]] = 1;
    else
      m[num[i]] += 1;

    if(m[num[i]] > num.size()/2){
      majorElement = num[i];
    }
  }
      
  return majorElement;
}

int main ()
{
  static const int arr[] = {1};
  vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  cout << majorityElement(v)<< endl;  
  return 0;
}