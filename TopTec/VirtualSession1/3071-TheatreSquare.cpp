/*
6 6 4
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  long long n, m, a;
  cin >> n >> m >> a;
  long long an, am, total;
  an = (n+a-1)/a;
  am = (m+a-1)/a;
  total = am * an;
  cout << total;
  return 0;
}
