/*
3
3 3 3
2 2 2
1 1 1
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

vector< vector<int> > boxes;
int n;


int stackBox(int bottom_box, vector<bool> list){
  list[bottom_box] = true;
  cout << " for box " << bottom_box << "with size " << boxes[bottom_box][0]  << endl;
  int max_height = 0;
  for(int i = 0; i < n; i++){
    if(!list[i] && boxes[bottom_box][0] > boxes[i][0] &&
                   boxes[bottom_box][1] > boxes[i][1] &&
                   boxes[bottom_box][2] > boxes[i][2]
      ){
      int temp;
      temp = boxes[i][1];
      temp += stackBox(i, list);
      if(temp > max_height)
        max_height = temp;
    }
  }
  return max_height;
}

int main ()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    boxes.push_back(vector<int>(3));
    for(int j = 0; j < 3; j++){
      scanf("%d", &boxes[i][j]);
    }
  }


  int max_height = 0;
  for(int i = 0; i < n; i++){
    vector< bool > tested(n, false);
    int temp = boxes[i][1];
    temp += stackBox(i, tested);
    if(temp > max_height)
        max_height = temp;
  }
  cout << " max " << max_height << endl;

  return 0;
}
 