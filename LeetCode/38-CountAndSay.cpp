/*
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

string countAndSay(int n) {
  int counter = 0;
  string str = "1", aux;
  char currentChar;
  for(int i = 0; i < n-1; i++){
    counter = 1;
    if(str.size() <= 1)
      aux = "11";
    else{
      for(int j = 0; j < str.size(); j++){
        if(counter == 1){
          currentChar = str[j];
        }
        if(currentChar != str[j+1]){
          aux += to_string(counter) + currentChar;
          counter = 0;
        }
        counter++;
      }
    }
    str = aux;
    aux = "";
  }
  return str;
}

int main (){
  cout << countAndSay(100) << endl;

  return 0;
}

//1, 11, 21, 1211, 111221, 312211, 13112221