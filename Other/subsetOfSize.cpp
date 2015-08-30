/*
Hello World!
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


string getSubset(string myString, int pos, int k){
  string newString = "";
  for(int i = 0; i < k; i++){
    newString += myString[pos+i];
  }
  return newString;
}

vector<string> getSubsets(string myString, int k){
  int n = myString.size();
  vector<string> subsets;
  for(int i = 0; i <= n - k; i++){
    string str = getSubset(myString, i, k);
    subsets.push_back(str);
  }
  return subsets;
}

int main ()
{
  vector<string> myvec = getSubsets("string", 3);
  for(int i = 0; i < myvec.size(); i++){
    cout << myvec[i] << " ";
  }
  cout << endl;

  return 0;
}
 