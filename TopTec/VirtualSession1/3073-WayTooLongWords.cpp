/*
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis
*/

//Accepted
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{ 
  int cases;
  cin >> cases;
  string word;
  while(cases--){
    cin >> word;
    if(word.size() > 10){
      cout << word[0] << word.size()-2 << word[word.size()-1]<<endl;
    } else
      cout << word << endl;
  }
  return 0;
}
