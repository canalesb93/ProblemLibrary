#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

string compressString(string str, int length){
  string newStr = "";
  for(int i = 0; i < length; i++){
    int count = 1;
    while(str[i] == str[i+count]){
      count++;
    }
    newStr.push_back(str[i]);
    string number = to_string(count);
    newStr+=number;
    i+=count-1;
  }
  if(newStr.length() > length)
    return str;
  return newStr;
}


int main ()
{

  string str = "Ricardo";
  string str2 = "aaabbbaaccccccccccccaaaaccc";
  cout << compressString(str, str.length()) << endl;
  cout << compressString(str2, str2.length()) << endl;
  
  return 0;
}