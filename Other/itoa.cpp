/*
Hello World!
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

/* itoa:  convert n to characters in s */
void itoa(int n){
  int temp_n = n*10, size = 0;
  while(temp_n/=10)
    size++;

  char s[size];
  int i = size;
  s[i--] = '\0'; /* set null at the end of string */ 
  do {       /* generate from back to front */ 
    s[i--] = n % 10 + '0';   /* get next digit */
    n/=10;
  } while (size--);     /* delete it */
  printf("%s\n", s);
}

int main ()
{
  itoa(21);
  return 0;
}
