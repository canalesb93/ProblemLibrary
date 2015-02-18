#include <iostream>

using namespace std;

string reverseString(string str){
  char temp;
  int len= str.length();
  for(int i = 0; i < len/2; i++){
    temp = str[i];
    str[i] = str[len-1-i];
    str[len-1-i] = temp;
  }
  
  return str;
}

int main ()
{

  cout << reverseString("test") << endl;
  cout << reverseString("Testing") << endl;
  return 0;
}
