/*
3
1 2 3

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

long long arr[100001];

int main ()
{
  long long n;

  scanf("%lld", &n);
  long long removed = 0, size = n, charges = 0, last = n-1;
  long long pos = 0;
  for(int i = 0; i < n; i++){
    scanf("%lld", &arr[i]);
  }

  sort(arr, arr + n);

  // cout << arr[0] << endl;
  while(size){

    // cout << "at num " << pos << endl;
    if(arr[last] - removed >= size){
      charges++;
      size--;
      last--;
      // cout << "removed from top" << endl;
    } else if(arr[pos] - removed < size){
      removed++;
      charges++;
      // cout << "removed a level " << endl;
      while(arr[pos] - removed <= 0 && pos <= last){
        pos++;
        size--;
        // cout << "moved a pos" << endl;
        // cout << "pos incr " << pos << endl;
      }
    }



    // cout << "size " << size <<endl;



  }
  
  printf("%lld\n", charges);

  return 0;
}
 