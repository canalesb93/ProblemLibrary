/*
8
0 0 0 0 0 0 0 0
*/
// 2
// -6 6
// 6
// -3 -10 -5 11 4 4

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

int N, total = 0;
vector<int> numbers, differences;
int differenceCount[24] = { 0 };

int main ()
{

  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    int input;
    scanf("%d", &input);
    numbers.push_back(input);
  }
  sort(numbers.begin(), numbers.end());
  numbers.push_back(numbers.front()+24);

  // for(int i = 0; i < numbers.size(); i++)
  //   printf("%d ", numbers[i]);
  // printf("\n");

  for(int i = 0; i < N; i++){
    int diff = numbers[i+1] - numbers[i];
    // cout << "For numbers " << numbers[i] << " and " << numbers[i+1] << " the diff is " << diff << endl;
    differences.push_back(diff);
    differenceCount[diff]++;
  }



  // for(int i = 0; i < differences.size(); i++)
  //   printf("%d ", differences[i]);
  // printf("\n");

  // for(int i = 0; i < 24; i++)
  //   printf("%d ", differenceCount[i]);
  // printf("\n");
  int totalone = 0, totaltwo = 0;
  for(int i = 0; i < differences.size(); i+=2){
    totalone += differences[i];
    totaltwo += differences[i+1];
  }

  int minim = min(totalone, totaltwo);
  printf("%d\n", minim);



  return 0;
}
