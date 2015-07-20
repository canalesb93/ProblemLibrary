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
map<pair<int,int>, int> m;
int countPaths(int x, int y, int limit_x, int limit_y){
  if(m[make_pair(x,y)] == -1) return 0; // if path blocked
  if(x == limit_x-1 && y == limit_y-1) return 1; // if at the end of path

  if(m[make_pair(x,y)] != 0) return m[make_pair(x,y)]; // if cached, return cache

  int count = 0;
  if(x < limit_x-1) count += countPaths(x+1, y, limit_x, limit_y);
  if(y < limit_y-1) count += countPaths(x, y+1, limit_x, limit_y);

  m[make_pair(x,y)] = count; // cache answer
  return m[make_pair(x,y)];
}

int main ()
{

  // m[make_pair(1,1)]=-1;//blocks in the map
  // m[make_pair(2,0)]=-1;//blocks in the map
  cout << countPaths(0,0,10,10) <<endl; // paths found
  return 0;
}
 