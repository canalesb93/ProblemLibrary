/*
3 27
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main ()
{
  int m, h;
  cin >> h >> m;
  double anglem, angleh;
  anglem = (m/60.0) * 360;
  angleh = (fmod(h,12.0))/12 * 360 + anglem/12;
  cout << abs(anglem - angleh) << endl;
  return 0;
}
