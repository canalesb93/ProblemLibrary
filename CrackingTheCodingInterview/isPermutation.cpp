#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int len1, len2;
bool isPermutation(char arr1[], char arr2[]){
  sort(arr1, arr1+len1);
  sort(arr2, arr2+len2);
  return equal(arr1, arr1+len1, arr2);
}

int main ()
{
  string s1 = "test", s2 = "estt";
  len1 = s1.length();
  len2 = s2.length();
  if(len1 != len2){
    cout << "Not a permutation" << endl;
  } else {
    char arr1[len1], arr2[len2];
    for(int i = 0; i < len1; i++){
      arr1[i]=s1[i];
      arr2[i]=s2[i];
    }
    if(isPermutation(arr1, arr2))
      cout << "A permutation!" << endl;
    else 
      cout << "Not a permutation" << endl;

  }

  return 0;
}