#include <iostream>
#include <cmath>

using namespace std;

int n = 5;

int maxIndex(int arr[]){
  int maxIndex = 0;
  
  for(int i = 1; i < n; i++){
    if( arr[i] > arr[maxIndex] )
      maxIndex = i;
  }
  return maxIndex;
}

int minIndex(int arr[]){
  int maxIndex = 0;
  
  for(int i = 1; i < n; i++){
    if( arr[i] < arr[maxIndex] )
      maxIndex = i;
  }
  return maxIndex;
}

int main ()
{
  int arr[] = {2,1,3,4,5};

  int maxIndexInt = maxIndex(arr);
  int minIndexInt = minIndex(arr);

  for(int i = 0; i < n; i++){
    cout << arr[i] << ", ";
  }
  cout << endl;

  int temp = arr[maxIndexInt];
  arr[maxIndexInt]=arr[minIndexInt];
  arr[minIndexInt]=temp;

  for(int i = 0; i < n; i++){
    cout << arr[i] << ", ";
  }
  cout << endl;

  return 0;
}