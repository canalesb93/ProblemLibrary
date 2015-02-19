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
#include <ctype.h>

using namespace std;

string sum_array(vector<string> holder, int nRows){
  string ans;
  for(int i = 0; i < nRows; i++){
    ans += holder[i];
  }
  return ans;
} 

string convert(string s, int nRows) {
  vector<string> holder(nRows, "");
  int counter = 0;
  while(counter < s.size()){
    for(int j = 0; j < nRows; j++){
      holder[j] += s[counter];
      if(++counter >= s.size()){
        return sum_array(holder, nRows);
      }
    }
    for(int k = nRows-2; k > 0; k--){
      holder[k] += s[counter];
      if(++counter >= s.size()){
        return sum_array(holder, nRows);
      }
    }
  }
  
  return sum_array(holder, nRows);
}

int main ()
{
  cout << convert("PAYPALISHIRING", 4) << endl;

  return 0;
}



// PAYPALISHIRING 
// PAHNAPLSIIGYIR


// P   A   H   N
// A P L S I I G
// Y   I   R

// P     I     N
// A   L S   I G
// Y A   H R
// P     I