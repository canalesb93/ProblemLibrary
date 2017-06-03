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

vector<int> mySet;

void placeSet(int n, vector< vector<int> > &subsets, vector<int> mySet){
  if(n < 0) return; // base case

  placeSet(n-1, subsets, mySet);
  int number = mySet[n];
  
  int size = subsets.size();
  for(int i = 0; i < size; i++){
    vector<int> newSubset = subsets[i];
    newSubset.push_back(number);
    subsets.push_back(newSubset);
  }
}



vector< vector<int> > getAllSubsets(vector<int> mySet){
  vector< vector<int> > subsets;
  subsets.push_back(vector<int>());
  placeSet(mySet.size()-1, subsets, mySet);

  return subsets;
}

int main ()
{

  int myints[] = { 1, 2, 3 };
  mySet = vector<int>(myints, myints + sizeof(myints) / sizeof(int) );

  vector< vector<int> > subsets = getAllSubsets(mySet);


  cout << "Subset count: " << subsets.size() << endl;
  for(int i = 0; i < subsets.size(); i++){
    cout << "{ ";
    for(int j = 0; j < subsets[i].size(); j++){
      cout << subsets[i][j] << " ";
    }
    cout << "} " << endl;
  }
  // for(int i = 0; i < mySet.size(); i++){
  //   cout << mySet[i] << " "; 
  // }


  return 0;
}
 