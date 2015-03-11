/*
1
2
5
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
unsigned long long fib[70] = { 0 };
unsigned long long fibonacci(unsigned long long i){
  if(i == 0) return 0;
  if(i == 1) return 1;
  if(fib[i]!=0) return fib[i]; //Returns cached result
  fib[i] = fibonacci(i-1) + fibonacci(i - 2); //cache result
  return fib[i];
}

int main ()
{
  unsigned long long n;
  while(scanf("%llu", &n) == 1){
    n = n % 60;
    printf("%llu\n", fibonacci(n)%10);
  } 


  return 0;
}
