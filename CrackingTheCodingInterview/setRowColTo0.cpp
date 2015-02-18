#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main ()
{

  int arr[3][3] = {{1,2,3},{4,5,6},{7,0,9}};
  
  bool arrRowFlag[3] = { 0 };
  bool arrColFlag[3] = { 0 };
  for(int i = 0; i < 3;i++){
    for(int j = 0; j < 3;j++){
      if(arr[i][j]==0){
        arrRowFlag[i]=true;
        arrColFlag[j]=true;
      }
    }
  }

  for(int i = 0; i < 3;i++){
    for(int j = 0; j < 3; j++){
      if(arrRowFlag[i] || arrColFlag[j]){
        arr[i][j]=0;
      }
    }
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}