/*
Hello World!
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
// 000123
int stringToInt(string myString){
  int accumulated = 0, counter = 0, current;
  for(int i = myString.length()-1; i >= 0; i--){
    current = myString[i]-'0';
    current *= pow(10, counter);
    accumulated += current;
    current = 0;
    counter++;
  }
  return accumulated;
}

int main ()
{
  cout << stringToInt("123") << endl;
  return 0;
}
