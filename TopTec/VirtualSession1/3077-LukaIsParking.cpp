/*
5 3 1
3 5
1 6
2 8
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  int prices[3];
  for(int i =0; i < 3; i++)
    cin >> prices[i];
  int truck1enter, truck1exit;
  int truck2enter, truck2exit;
  int truck3enter, truck3exit;
  cin >> truck1enter >> truck1exit;
  cin >> truck2enter >> truck2exit;
  cin >> truck3enter >> truck3exit;
  int count = 0, kunas = 0;
  for(int i = 1; i <= 100; i++){
    if(truck1enter == i)
      count++;
    else if(truck1exit == i)
      count--;

    if(truck2enter == i)
      count++;
    else if(truck2exit == i)
      count--;

    if(truck3enter == i)
      count++;
    else if(truck3exit == i)
      count--;

    if(count > 0)
      kunas += count * prices[count-1];
  }
  cout << kunas;
  return 0;
}
