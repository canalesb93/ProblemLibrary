/*
5
RD TQIJW GWTYMJWX INFWD JSYWNJX ZXJ F XNRUQJ JSHWDUYNTS YJHMSNVZJ
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
XVIDRE TFCCVXZRKV GIFXIRDDZEX TFEKVJK UVTIPGKZFE
XVIDRE TFCCVXZRKV GIFXIRDDZEX TFEKVJK
DDDDDDDDDDDDDD ZZZ
*/


#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <ctype.h>

using namespace std;
 
int main(){
  int c;
  scanf("%d", &c);
  cin.ignore();
  while(c--){
    string initial;
    int counter[26] = { 0 };
    getline(cin, initial);
    int size = initial.size();
    // cout << initial << endl;
    int top = 0, topPlace = 0;
    bool equals = true;
    for(int i = 0; i < size; i++){
      if(isalpha(initial[i])){
        int character = initial[i] - 'A';
        counter[character]++;
        if(counter[character] > top){
          equals = false;
          top = counter[character];
          topPlace = character + 'A';
        } else if(counter[character] == top){
          equals = true;
        }
      }
    }

    int difference = topPlace - 'E';
    // cout << "difference: " << difference << endl;

    // cout << "here: " << (initial[0] - 'A') - difference << endl;
    // cout << "TOP: " << top << " and char is: " << (char) (topPlace) << endl;
    if(equals){
      cout << "NOT POSSIBLE" << endl;
    } else {
      for(int i = 0; i < size; i++){
        if(isalpha(initial[i])){
          initial[i] = 'A' + (((initial[i] - 'A') - difference)+ 26)%26;
        }
      }
      cout << (difference + 26)%26 << " " << initial << endl;
    }
  }

  return 0;
}