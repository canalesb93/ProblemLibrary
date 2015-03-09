/*
4
3
2
1
0
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
  int cases;
  scanf("%d", &cases);
  while(cases--){
    int N;
    scanf("%d", &N);
    printf("%d\n", (((((N+3)*2)+3)*2)+3)*2);
  }

  return 0;
}
