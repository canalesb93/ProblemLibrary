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
#include <utility>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int removeElement(int A[], int n, int elem) {
  int tail = n - 1;
  int i = 0;
  while(i <= tail){
    if(A[i]==elem){
      A[i] = A[tail--];
      continue;
    }
    i++;
  }
  return tail+1;
}

int main ()
{
  int arr[] = { 4, 1, 5, 3, 0, 4, 2};

  cout << removeElement(arr, 7, 4) << endl;
  return 0;
}
