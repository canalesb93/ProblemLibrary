#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
bool isPermutation(string myString){
  int length = myString.length();
  int middle = length/2, even = 0;
  int start = 0;

  if(length%2==0){
    even = 1;
  }

  for(int i = 1; i <= middle; i++ ){
    if(myString[middle + i - even] != myString[middle - i])
      return false;
  }
  return true;
}


int main ()
{
  string test = "test", test2 = "tesset", test3 = "tes";
  cout << isPermutation(test3) << endl;
  return 0;
}
