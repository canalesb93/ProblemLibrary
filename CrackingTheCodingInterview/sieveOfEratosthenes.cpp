/*
1000
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

vector<int> sieve;
vector<int> primes;

void generatePrimes(int max){
  for (int i = 1; i < max + 1; ++i)
     sieve.push_back(i);   // you'll learn more efficient ways to handle this later
  sieve[0]=0;
  for (int i = 2; i < max + 1; ++i) {   // there are lots of brace styles, this is mine
     if (sieve[i-1] != 0) {
        primes.push_back(sieve[i-1]);
        for (int j = 2 * sieve[i-1]; j < max + 1; j += sieve[i-1]) {
            sieve[j-1] = 0;
        }
     }
  }
}
int main ()
{
  int max;
  // scanf("%d", &max);
  max = 1000000;
  generatePrimes(max);
  printf("Prime Total: %lu\n", primes.size());
  // for(int i = 0; i < primes.size(); i++){
  //   printf("%d\n", primes[i]);
  // }

  return 0;
}