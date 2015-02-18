/*
3
0 3
3 5
10 19
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long fib[1000] = { 0 };
long long fibonacci(long long i){
  if(i == 0) return 0;
  if(i == 1) return 1;
  if(fib[i]!=0) return fib[i]; //Returns cached result
  fib[i] = fibonacci(i-1) + fibonacci(i - 2); //cache result
  return fib[i];
}

int main ()
{
  int count, n, m;
  long long sum = 0;
  cin >> count;
  while(count !=0){
    cin >> n >> m;
    for(int i = n; i <= m; i++){
      sum = sum + fibonacci(i);
    }
    cout << fmod(sum, 1000000007) << endl;
    count--;
  }
  

  return 0;
}
