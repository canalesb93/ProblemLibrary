/*
B34
*/
#include <iostream>
#include <cmath>

using namespace std;

int digitToValue(char c){
  // Converts char to its int value
  if(c>='0' && c<='9') 
    return c-'0';
  else if(c>='A' &&c<='F')
    return 10 + c - 'A'; 
  else if (c >= 'a' && c <= 'f') 
    return 10 + c - 'a';
  return -1;
}

int convertToBase(string number, int base){
  if(base < 2 || (base > 10 && base != 16))
    return -1;
  
  int value = 0;
  for(int i = number.length()-1; i >= 0; i--){
    int digit = digitToValue(number[i]);
    if(digit < 0 || digit >= base)
      return -1;
    int exp = number.length() -1 -i;
    value += digit * pow(base, exp);
  }
  return value;
}


int main ()
{
  string hex; 
  cin >> hex;
  int base = 16;

  cout << convertToBase(hex, base) << endl;
  return 0;
}