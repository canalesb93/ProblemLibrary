/*
265 105 678 655 108 731 491 128 713 319 830 793 916 991 529 906 714 437 950 303 743 181 291 733 365 912
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

int main()
{
  int input, swaps = 0;


  vector<int> array;
  while(scanf("%d", &input) == 1){
    array.push_back(input);
  }
  
  for (int i = 0 ; i < array.size() - 1; i++){
    for (int j = 0 ; j < array.size() - i - 1; j++){
      if (array[j] > array[j+1]){
        int temp = array[j];
        array[j]   = array[j+1];
        array[j+1] = temp;
        swaps++;
      }
    }
  }
  printf("%d\n", swaps);
  for (int i = 0 ; i < array.size(); i++ ){
    if(i){
      printf(" ");
    }
    printf("%d", array[i]);
  }
    
 
  return 0;
}