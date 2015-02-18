/*
2
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{ 
  // 75 / 2 ===== 37.5   36 
  int w;
  cin >> w;
  if(w<=2)
    cout << "NO" << endl;
  else if(w%2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
