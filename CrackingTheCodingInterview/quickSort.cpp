/*
Hello World!
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

void swap(vector<int> &arr, int left, int right){
  int temp = arr[left];
  arr[left] = arr[right];
  arr[right] = temp;
}

int partition(vector<int> &arr, int left, int right){
  int pivot = arr[(left+right)/2];
  while(left <= right){
    //find elements 'left' that should be 'right'
    while(arr[left] < pivot) left++;
    // and vice versa
    while(arr[right] > pivot) right--;

    // swap
    if(left <= right){
      swap(arr, left, right);
      left++;
      right--;
    }
  }
  return left;
}


void quickSort(vector<int> &arr, int left, int right){
  int index = partition(arr, left, right);
  if(left < index - 1) // sort left side
    quickSort(arr, left, index-1);
  if(index < right) // sort right side
    quickSort(arr, index, right); 
}

int main ()
{
  int myArr[] = { 5, 3, 1, 8, 7, 3, 2, 6, 3, 9};

  vector<int> arr(myArr, myArr + sizeof(myArr) / sizeof(int) );
  quickSort(arr, 0, arr.size()-1);
  for(int i = 0; i < arr.size(); i++){
    cout<<arr[i]<< " ";
  }
  cout << endl;
  cout << endl;
  cout << endl;

  return 0;
}
