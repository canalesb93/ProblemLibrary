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

int main ()
{
  int a, b;
  

  do{
    cin >> a >> b;
    if(a != 0 && b != 0){
      cout << a+b << endl;
    }
  }while(a != 0 && b != 0);

  return 0;
}
 