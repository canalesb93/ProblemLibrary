/*
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

vector<int> twoSum(vector<int> &nums, int target) {
  map<int, int> myMap;
  vector<int> answer;
  for(int i = 0; i < nums.size(); i++){
    if(myMap.find(target - nums[i]) != myMap.end()){
      answer.push_back(myMap[target - nums[i]] + 1); answer.push_back(i + 1);
      return answer;
    } else {
      myMap[nums[i]] = i;
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
