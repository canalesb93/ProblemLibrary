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

//   Using XOR ( ^ operator )
//    a | b | a^b
//    0 | 0 |  0
//    0 | 1 |  1
//    1 | 0 |  1
//    1 | 1 |  0

//   1, 2, 1, 2, 3
//   0000 0001
//   0000 0010
//   0000 0001
//   0000 0010
//   0000 0011

//r= 0000 0011

int singleNumber(int A[], int n) {
  int r = 0;
  for(int i = 0; i < n; i++){
    r = r ^ A[i];
  }
  return r;
}

int main ()
{
  int arr[] = { 1, 2, 1, 2, 3 };
  cout << singleNumber(arr, 5) << endl;  
  return 0;
}
