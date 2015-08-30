/*
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <fstream>
 
using namespace std;


pair<int, int> posA = make_pair(0,0);
pair<int, int> posB = make_pair(7,7);


int changes[8][2] =
    {
        {-2,-1},
        {-2,1},
        {-1,-2},
        {-1,2},
        {1,-2},
        {1,2},
        {2,-1},
        {2,1}
    };

int getDistanceMin(pair<int, int> pos){
  return min(abs(pos.first - posB.first), abs(pos.second - posB.second));
}

int getDistanceMax(pair<int, int> pos){
  return max(abs(pos.first - posB.first), abs(pos.second - posB.second));
}

int getToB(vector< vector<int> > board, pair<int,int> pos){
  if(posA.first == posB.first && posA.second == posB.second)
    return 0;

  queue< pair<int, int> > q;
  queue< int > qCounter;
  q.push(pos);
  qCounter.push(1);
  int iterations = 0;
  int minimumDistance = 100;
  while(!q.empty()){
    int count = qCounter.front();
    qCounter.pop();
    pos = q.front();
    q.pop();
    cout << "its: " << ++iterations << endl;
    cout << count << endl;
    cout << pos.first << " " << pos.second << endl;
    if(getDistanceMax(pos) < minimumDistance)
      minimumDistance = getDistanceMax(pos);
    if(minimumDistance < 0)
      minimumDistance = 1;

    for(int i = 0; i < 8; i++){
      int x = pos.first + changes[i][0];
      int y = pos.second + changes[i][1];
      if((x >= 0 && x < 8) && (y >= 0 && y < 8)){
        if(x == posB.first && y == posB.second){
          return count;
        }
        pair<int, int> newPair = make_pair(x,y);
        int distance = getDistanceMin(newPair);
        if(distance <= minimumDistance){
          // cout << "for " << x<< ", " << y << " distance: " << distance << " vs " << minimumDistance;
          if (count < board[x][y]){
            // cout << "  === ADDED";
            board[x][y] = count;
            q.push(newPair);
            qCounter.push(count+1);
          }
        }
        // cout << endl;
      }
    }
  }
  return 100;

}

int main ()
{
  vector< vector<int> > board(8, vector<int>(8));
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      board[i][j] = 100;
    }
  }

  cout << getDistanceMax(posA) << endl;

  cout << getToB(board, posA) << endl;

  



  cout << endl;
  cout << endl;
  return 0;
}
 