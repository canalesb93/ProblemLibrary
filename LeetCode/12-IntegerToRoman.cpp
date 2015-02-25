/*
Hello World!
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

// XIV

string intToRoman(int num)
{
  struct romandata_t { int num; char const* numeral; };
  const struct romandata_t romandata[] = {
    {1000, "M"}, {900, "CM"},
    {500, "D"}, {400, "CD"},
    {100, "C"}, { 90, "XC"},
    { 50, "L"}, { 40, "XL"},
    { 10, "X"}, { 9, "IX"},
    { 5, "V"}, { 4, "IV"},
    { 1, "I"},
    { 0, NULL} // end marker
  };

  string result;
  for (const romandata_t* current = romandata; current->num > 0; ++current){
    while (num >= current->num){
      result += current->numeral;
      num -= current->num;
    }
  }
  return result;
}

int main ()
{

  cout << intToRoman(3999) << endl;  
  return 0;
}
