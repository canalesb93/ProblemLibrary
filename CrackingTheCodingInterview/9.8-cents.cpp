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

int makeChange(int n, int denom){
  int next_denom = 0;
  switch(denom){
    case 25:
      next_denom = 10;
      break;
    case 10:
      next_denom = 5;
      break;
    case 5:
      next_denom = 1;
      break;
    case 1:
      return 1;
  }

  int ways = 0;
  for(int i = 0; i * denom <= n; i++){
    ways += makeChange(n - i * denom, next_denom);
  }
  return ways;
}


int main ()
{

  for(int i = 0; i < 1000; i++){
    cout << makeChange(i, 25) << endl;
  }

  return 0;
}
 