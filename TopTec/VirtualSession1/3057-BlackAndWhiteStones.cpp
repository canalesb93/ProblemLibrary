/*
10 9
WWWBWB
*/

//Accepted
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  long long A, B;
  long long worst;
  //white count before stones[blackCount]
  int blackCount = 0, whiteCount = 0, lastBlackMoved;
  string stones;
  cin >> A >>B;
  cin >> stones;
  
  //counts total black stones
  for(int i = 0; i<stones.size();i++)
    if(stones[i]=='B')
      blackCount++;

  //counts whites stones before blackCount
  for(int i = 0; i<blackCount;i++)
    if(stones[i]=='W')
      whiteCount++;

  if(blackCount == 0 || whiteCount == 0){
    cout << 0 << endl;
    return 0;
  }

  // cout << "B: " << blackCount << endl << "W<-Bc: " << whiteCount << endl;
  worst = whiteCount * A;
  // cout << "Worst: " << worst << endl << endl;

  lastBlackMoved = blackCount-1;
  for(int i = blackCount-1; i >= 0; i--){
    if(stones[i]=='W'){
      long long min = worst;
      int closestBlack;
      min -= A;
      for(int j = lastBlackMoved+1; j<stones.size();j++ )
        if(stones[j]=='B'){
          closestBlack=j;
          break;
        }


      min += (A-B)*(closestBlack-i);
      // cout << "MIN at "<< closestBlack << " - " << i << ": "<<min << endl;
      if(min > worst){
        break;
      } else {
        lastBlackMoved=closestBlack;  
        worst = min;
      }
    }
  }
  cout << worst << endl;

  return 0;
}
