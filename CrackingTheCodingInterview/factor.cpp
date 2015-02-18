/*
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> byeFactor(vector<int> arr){
  bool flag = false;
  sort(arr.begin(), arr.begin()+arr.size());
  for(int i = 0; i < arr.size()-1;i++){
    flag = false;
    if(arr[i]==arr[i+1]){
      flag = true;
    }
    for(int j = i + 1;j < arr.size();j++){
      if(arr[j]%arr[i]==0){
        arr.erase(arr.begin()+j);
        j--;
      }
    }
    if(flag){
      arr.erase(arr.begin()+i);
      i--;
    }
  }
  return arr;
}

int main ()
{
  int myints[] = {16,77,16,77,11};
  vector<int> myVector (myints, myints + sizeof(myints) / sizeof(int) );
  myVector = byeFactor(myVector);
    for(int i = 0; i < myVector.size();i++){
      cout << myVector[i]<< " ";
    }
    cout << endl;
  }
  return 0;
}
