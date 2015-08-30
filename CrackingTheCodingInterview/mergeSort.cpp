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

void partition(vector<int> & data, int low, int high);
void merge(vector<int> &data, int low, int middle, int high);



// MERGESORT starts here.
void mergesort(vector<int> &data){
  partition(data, 0, data.size()-1);
}

void partition(vector<int> & data, int low, int high){
  if (low < high){
    int mid = (low + high)/2;
    partition(data, low, mid);
    partition(data, mid+1, high);
    merge(data, low, mid, high);
  }
}

void merge(vector<int> & data, int low, int middle, int high){

  vector<int> tmp(data.size());
  for(int i = low; i <= high; i++){
    tmp[i] = data[i];
  }

  // Use 2 pointers, one for each half
  int helperLeft = low;
  int helperRight = middle+1;
  int current = low; // keeps track of original data[] position

  while (helperLeft <= middle && helperRight <= high){
    // add whichever is smaller, then update pointers
    if (tmp[helperLeft] < tmp[helperRight]){ 
      data[current++] = tmp[helperLeft++];
    }
    else if (tmp[helperRight] < tmp[helperLeft]){
      data[current++] = tmp[helperRight++];
    }
    else{ // if they are the same number add both.
      data[current++] = tmp[helperLeft++];
      data[current++] = tmp[helperRight++];
    }
  }

  /* only add "missing" left side because right side would already be there since we 
   * copied data[] to tmp[] 
   */
  while (helperLeft <= middle){
    data[current++] = tmp[helperLeft++];
  }

}

int main ()
{
  int myArr[] = { 5, 3, 1, 8, 7, 2, 6, 3, 9};

  vector<int> arr(myArr, myArr + sizeof(myArr) / sizeof(int) );
  mergesort(arr);
  for(int i = 0; i < arr.size(); i++){
    cout<<arr[i]<< " ";
  }
  cout << endl;
  cout << endl;
  cout << endl;

  return 0;
}


