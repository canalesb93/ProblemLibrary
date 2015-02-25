/*
0000000000
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

using namespace std;

string initial;
long long counter = 0;

void join(long long bottom, long long middle, long long top){
  // cout << "For bottom: " << bottom << " and middle: " << middle << " and top " << top << endl;
  if(bottom == top){
    if(initial[bottom] >= '0' &&  initial[bottom] <= '9' && (initial[bottom] - '0')%3 == 0 ){
      counter++;
      return;
    }
    // cout << "  bottom reached and multiple" << endl;
    return;
  }


  long long modsRight[4] = { 0 };
  long long modsLeft[4] = { 0 };

  long long total = 0;

  //RIGHT
  for(long long i = middle+1; i <= top; i++){
    if(initial[i] >= '0' &&  initial[i] <= '9'){
      total += initial[i] - '0';
      modsRight[total%3]++;
    } else {
      break;
    }
  }

  total = 0;
  //LEFT
  for(long long i = middle; i >= bottom; i--){
    if(initial[i] >= '0' &&  initial[i] <= '9'){
      total += initial[i] - '0';
      modsLeft[total%3]++;
    } else {
      break;
    }
  }

  // for(long long i = 0; i < 3; i++){
  //   cout << "  modsLeft[" << i << "] = " << modsLeft[i] << endl;
  //   cout << "  modsRight[" << i << "] = " << modsRight[i] << endl;
  // }
  counter += modsLeft[0] * modsRight[0];
  counter += modsLeft[1] * modsRight[2];
  counter += modsLeft[2] * modsRight[1];
}

void divideAndConquer(long long bottom, long long top){
  if(bottom < top){
    long long middle = (bottom+top)/2;
    divideAndConquer(bottom, middle);
    divideAndConquer(middle+1,top);
    join(bottom,middle,top);
  } else if(bottom > top){

  } else{
    join(bottom,-1,top);
  }
}

int main ()
{
  ios_base::sync_with_stdio(false);
  cin >> initial;
  long long len = initial.size();
  divideAndConquer(0, len-1);
  cout << counter << endl;
  // cout << checkMultiple(4,6) << endl;

  return 0;
}
