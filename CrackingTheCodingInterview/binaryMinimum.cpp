/*
5
3 4 5 1 2
*/

#include <iostream>
#include <cmath>

using namespace std;

// Binary Search Algorithm for minimum broken array
// Requires sorted array 

//           
int n;
int arr[] = {};

int binarySearch(int start, int end){
  int half;
  if (start >= end){
    return start;
  }
  else{
    half = (start + end) / 2;
    if (arr[half] > arr[end])
      return(binarySearch(half+1, end));
    else 
      return(binarySearch(start, half));
  }
}

int main ()
{
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++){
    cout <<  arr[i] << " ";
  }
  cout << endl;

  cout << binarySearch(0,n-1) << endl;
  return 0;
}