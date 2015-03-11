/*
Y
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

// ABCDEF % 26

int main ()
{ 
  string input;
  int remainder, total = 1;
  cin >> input;
  for(int i = 0; i < input.size(); i++){
    if(input[i] >= 'A' && input[i] <= 'Z'){
      total *= (input[i] - 'A' + 1);
      total = total % 26;
      // printf("for letter: %c, %lld\n", input[i], input[i] - 'A' + 1);
      // printf("%d\n", total);
    }
  }

  
  if(total < 10)
    printf("0%d\n", total);
  else
    printf("%d\n", total);

  return 0;
}
