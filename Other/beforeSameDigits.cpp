/*
3
1
2
2171
*/

#include <iomanip>
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

// 10987598322

string sameDigits(string num){
  int arr[10] = { 0 };
  for(int i = num.size()-1; i >= 0; i++){
    int current = num[i] - '0';
    for(int j = current; j >= 0; j--){
      if(arr[j]>0){
        cout << "Eere " <<endl;
        char aux = num[i];
        cout << arr[j] << endl;
        cout << aux << endl;
        cout << (char)(j + '0') << endl;
        num[i] = (char)(j + '0');
        num[arr[j]] = aux;
        return num;
      }
    }
    arr[current] = i;
  }
  return num;

}

int main(){
  cout << sameDigits("109875980203") << endl;
  return 0;
}