/*
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long int fib[1000] = { 0 };
long int fibonacci(int i){
  if(i == 0) return 0;
  if(i == 1) return 1;
  if(fib[i]!=0) return fib[i]; //Returns cached result
  fib[i] = fibonacci(i-1) + fibonacci(i - 2); //cache result
  return fib[i];
}

int generateFibonacciSlow(int i){//slow O(2^n)
  if(i == 0) return 0;
  if(i == 1) return 1;
  return (generateFibonacciSlow(i-1)+generateFibonacciSlow(i-2));
}

int main ()
{
  int i = 40;
  cout << "SLOW: " << generateFibonacciSlow(i) << endl;
  cout << "FAST: " << fibonacci(i) << endl;

  return 0;
}
