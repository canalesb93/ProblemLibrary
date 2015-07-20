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

map<int, int> m;

int countSteps(int n){
  if(n < 0) return 0;
  if(n == 0) return 1;
  if(m[n] != 0) return m[n];
  m[n] = countSteps(n-1) + countSteps(n-2) + countSteps(n-3);
  return m[n];
}

int main ()
{
  
  cout << countSteps(2) << endl;
  return 0;
}
 