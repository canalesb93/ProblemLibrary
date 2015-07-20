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

// uses a map to avoid duplicates, crazy orignal solution of mine
map<string, bool> generateMapPairs(int pairs){
  map<string, bool> new_valids;
  if(pairs <= 0){
    new_valids[""] = true;
    return new_valids;
  }

  map<string, bool> valids = generateMapPairs(pairs-1);

  for(map<string, bool>::iterator it = valids.begin(); it != valids.end(); it++){
    string temp = it->first;

    new_valids[temp + "()"] = true;
    new_valids["()" + temp] = true;
    new_valids["(" + temp + ")"] = true;
  }

  return new_valids;
}

vector<string> generatePairs(int pairs){
  map<string, bool> m = generateMapPairs(pairs);
  vector<string> vec;
  for(map<string, bool>::iterator it = m.begin(); it != m.end(); it++){
    vec.push_back(it->first);
  }
  return vec;
}

int main ()
{
  vector<string> pairs = generatePairs(4);
  for(int i = 0; i < pairs.size(); i++){
    cout << pairs[i] << endl;
  }

  return 0;
}
 