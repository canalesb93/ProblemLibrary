/*
5
abbaabbacdecde
*/
//
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

int counter[26] = { 0 }, top = 0;

int findFrequent(){
  int max = 0;
  int shift;
  for(int i = 0; i < 26; i++){
    // cout << (char)(i+'a') << counter[i] << " ";
    if(counter[i] > max){
      max = counter[i];
      shift = i;
    }
  }
  // cout << endl;
  return shift+1;
}
 
int main(){

  int ignored;
  string initial, copy;
  char topChar;
  cin >> ignored;
  cin >> initial;
  copy = initial;

  for(int i = 0; i < ignored; i++){
    int pos = initial[i] - 'a';
    counter[pos]++;
    // cout << initial[i] << counter[pos] << " ";
  }
  // cout << endl;
  // abbaab bacdecde
  for(int i = ignored; i < initial.size(); i++){
    top = findFrequent();
    // cout << "top/shift: " << (char)(top - 1 + 'a') << " or " << top << endl;

    copy[i] = (((copy[i] - 'a') + top)%26)+'a';
    
    // cout << "now: " << initial[i] << " becomes " << (char)((((initial[i] - 'a') + top)%26)+'a') <<  " and back 5: " << initial[i - ignored] << endl;
    counter[initial[i - ignored] - 'a']--;

    int pos = initial[i] - 'a';
    counter[pos]++;
  }


  // int shift = topChar - 'a';
  // cout << "shift if: " << shift<< endl;
  // for(int i = ignored; i < initial.size(); i++){
  //   cout << "this num: " << ((initial[i] - 'a') + shift)%26 << endl;
  // }
  cout << copy << endl;


  return 0;
}