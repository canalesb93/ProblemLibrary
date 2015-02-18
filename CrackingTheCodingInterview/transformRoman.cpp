#include <iostream>
#include <map>

using namespace std;

map<char,int> roman;

int transformRoman(string str){
  int count = 0;
  for(int i = 0; i < str.length(); i++){
    if(roman[str[i]] < roman[str[i+1]]){
      count -= roman[str[i]];
    } else {
      count += roman[str[i]];
    }
  }

  return count;
}

int main ()
{
  roman['I'] = 1;
  roman['V'] = 5;
  roman['X'] = 10;
  roman['L'] = 50;
  roman['C'] = 100;
  roman['D'] = 500;
  roman['M'] = 1000;

  cout << transformRoman("XXVII") << endl;
  cout << transformRoman("XXIV") << endl;
  cout << transformRoman("XL") << endl;
  cout << transformRoman("IV") << endl;
  cout << transformRoman("MCM") << endl;
  cout << transformRoman("CL") << endl;
  cout << transformRoman("CL") << endl;
  cout << transformRoman("MDCC") << endl;
  cout << transformRoman("CMXCIX") << endl;
  return 0;
}
