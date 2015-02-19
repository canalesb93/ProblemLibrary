/*
Hello World!
*/

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

vector<int> twoSum(vector<int> &numbers, int target) {
  vector<int> answer;
  int size = numbers.size();
  map<int, int> m;
  for(int i = 0; i < size; i++){
    if(m.find(numbers[i]) == m.end()){
      m[target - numbers[i]] = i;
    } else {
      answer.push_back(m[numbers[i]]+1);
      answer.push_back(i+1);
      break;
    }
  }
  return answer;
}

int main ()
{
  int myints[] = {2, 7, 11, 15};
  int target = 9;
  vector<int> numbers(myints, myints + sizeof(myints) / sizeof(int) );
  vector<int> answer;
  answer = twoSum(numbers, target);
  cout << answer[0] << " and " << answer[1] << endl;

  return 0;
}
