/*
HelloWorld!
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

double expVA(double x)
{
  double z;  // numero aleatorio z uniforme entre 0 y 1   
  do
  {
    z = ((double) rand() / RAND_MAX);
  }
  while ((z == 0) || (z == 1));

  return(-x * log(z));
}


int main() {
  cout << expVA(0.5) << endl; // -2147483648

  return 0;
}

