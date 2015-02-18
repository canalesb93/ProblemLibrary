/*
3
3 1 2 3
8 4 5 -1 -1 1 -1 -1 5
2 -1 -1
*/

#include <iomanip>
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

int kadane (int a[], int n);
 
int maxCircularSum (int a[], int n){
   int max_kadane = kadane(a, n);
    int max_wrap  =  0, i;
   for(i=0; i<n; i++)
   {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i];  // invert the array (change sign)
   }
 
   max_wrap = max_wrap + kadane(a, n);
 
   return (max_wrap > max_kadane)? max_wrap: max_kadane;
}
 

int kadane (int a[], int n){
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for(i = 0; i < n; i++){
        max_ending_here = max_ending_here + a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
 
int main(){

  int cases;
  int num_cities;
  cin >> cases;

  while (cases--){
    cin >> num_cities;
    int cost_array[num_cities];

    for (int i = 0; i < num_cities; ++i)
      cin >> cost_array[i];

    printf("%d\n", maxCircularSum(cost_array, num_cities));
  }

    
    return 0;
}