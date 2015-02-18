/*
7
8
10
13
15
19
20
23
17
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int num[9];
int total;
int ans[7];

int main ()
{
  for(int i = 0; i < 9; i++){
    cin >> num[i];
  }
  sort(num, num+9);

  do{
    total = 0;
    for(int i = 0; i < 7; i++){
      total+=num[i];
    }
    if(total == 100){
      for(int i = 0; i < 7; i++){
        ans[i] = num[i];
      }
      break;
    }

  }while(next_permutation(num, num+9));
  sort(ans, ans+7);
  for(int i = 0; i < 7; i++){
    cout << ans[i] << endl;
  }


  return 0;
}
