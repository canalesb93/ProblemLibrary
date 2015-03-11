/*
4 5
3 2 3 1 4
*/

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

// 2 + 3 + 1 
// 1->2->3->4->5->6->7->8


int N, M, lastPos = 1;
// 3 2 3
int getDistance(int num){
  int distance = 0;
  if(num == lastPos) return 0;
  if(num > lastPos)
    distance = num - lastPos;
  else
    distance = N+num - lastPos;
  lastPos = num;
  // printf("%d\n", distance);
  return distance;
}

int main ()
{
  scanf("%d %d", &N, &M);
  int totalTime = 0;
  for(int i = 0; i < M; i++){
    int task;
    scanf("%d", &task);
    totalTime += getDistance(task);
  }
  printf("%d\n", totalTime);

  return 0;
}
