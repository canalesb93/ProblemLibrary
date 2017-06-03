/*
3 27
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
  int h = 3;
  int m = 26;
  cin >> h >> m;

  // manually
  double minute_angle = (m / 60.0) * 360;
  double hour_angle = (h % 12)/12.0 * 360 + (minute_angle / 12.0);
  double angle_difference = fmod(abs((minute_angle - hour_angle)), 360.0);
  cout << " manually_angle " << min(360-angle_difference, angle_difference) << endl;

  // with formula
  double angle = fmod(abs((30.0*h + 0.5*m) - 6.0*m), 360);
  cout << " formula_angle: " << min(360-angle, angle) << endl;




  return 0;
}
 

 // 360 * (23%12) / 12 + 360 * (0 / 60) * (1/12)