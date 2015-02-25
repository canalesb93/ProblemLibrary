/*
abcdefghij
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


using namespace std;

string initial = "";
int top;
string LEKTIRA(int n, int m){
  string newStr ="";
  for(int i = n; i>=0; i--){
    newStr += initial[i];
  }
  for(int i = m; i > n; i--){
    newStr += initial[i];
  }
  for(int i = top; i > m; i--){
    newStr += initial[i];
  }
  // cout << newStr << endl;
  return newStr;
}

int main ()
{
  cin >> initial;
  string low = initial;
  top = initial.size() - 1;
  for(int i = 0; i < top-1; i++){
    for(int j = i+1; j < top; j++){
      string lekt = LEKTIRA(i, j);
      if(lekt < low)
        low = lekt;
    }
  }
  cout << low << endl;
  // LEKTIRA(2, 4);
  
  return 0;
}
