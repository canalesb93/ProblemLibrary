/*
0 0 0 0 0 
1 1 1 1 1
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#define NLABEL 5

using namespace std;

int main ()
{ 
  int connector1[NLABEL], connector2[NLABEL];
  for(int i = 0; i < NLABEL; i++){
    cin >> connector1[i];
  }
  for(int i = 0; i < NLABEL; i++){
    cin >> connector2[i];
  }
  for(int i = 0; i < NLABEL; i++){
    if(connector1[i]==connector2[i]){
      cout << "N" << endl;
      return 0;      
    } 
  }
  cout << "Y" << endl;
  return 0;
}
