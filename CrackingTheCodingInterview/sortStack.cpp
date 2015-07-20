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


stack<int> sortStack(stack<int> s){
  stack<int> r;
  int temp;

  while(!s.empty()){
    temp = s.top();
    s.pop();
    while(!r.empty() && r.top() > temp){
      s.push(r.top());
      r.pop();
    }
    r.push(temp);
  }
  return r;
}


int main ()
{
  stack<int> s;
  s.push(4);
  s.push(23);
  s.push(54);
  s.push(32);
  s.push(9);
  s.push(1);

  s = sortStack(s);

  while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
  }


  return 0;
}
 