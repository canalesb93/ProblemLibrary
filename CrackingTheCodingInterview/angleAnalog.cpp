/*
3 27
*/

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
  int h=3, m=30;
  cout << "Input hours then minutes to find their difference in degrees on an analog clock." << endl;
  cin >> h >> m;
  cout << h << ":" << m << endl;

  cout << "Difference is " << abs(fmod(( 30*h - 5.5*m ), 360)) << endl;
  return 0;
}