/*
5
45 3424 999999999 5 5
3 6
999999999 54 45
4 2 3 5 1 3
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


int main ()
{
  int N, Q1Count, Q2Count;
  vector<int> list, Q1, Q2;
  map<int, bool> present;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int temp;
    scanf("%d", &temp);
    present[temp] = true;
    list.push_back(temp);
  }
  scanf("%d %d", &Q1Count, &Q2Count);
  for(int i = 0; i < Q1Count; i++){
    int temp;
    scanf("%d", &temp);
    if(present[temp])
      printf(":)\n");
    else
      printf(":(\n");
  }
  sort(list.begin(), list.end());
  for(int i = 0; i < Q2Count; i++){
    int temp;
    scanf("%d", &temp);
    printf("%d\n", list[temp-1]);
  }

  return 0;
}
