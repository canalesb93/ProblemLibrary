/*
1 8 1 8
1 10 2 5
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

int main (){
  
  int gunnar[4];
  int emma[4];
  scanf("%d %d %d %d", &gunnar[0], &gunnar[1], &gunnar[2], &gunnar[3]);
  scanf("%d %d %d %d", &emma[0], &emma[1], &emma[2], &emma[3]);

  int gunnarTotal = 0, emmaTotal = 0;

  for(int i = 0; i < 4; i++){
    gunnarTotal += gunnar[i];
    emmaTotal += emma[i];
  }

  if(gunnarTotal > emmaTotal)
    printf("Gunnar\n");
  else if(gunnarTotal < emmaTotal)
    printf("Emma\n");
  else
    printf("Tie\n");

  return 0;
}
