// UNFINISHED
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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int middle = (nums1.size() + nums2.size())/2;
  vector<int> v;

  int a = 0, b = 0;
  for(int i = 0; i < nums1.size() + nums2.size(); i++){
    if(a < nums1.size() && b < nums1.size()){
      if(nums1[a] < nums2[b]){
        v.push_back(nums1[a]);
      } else {
        v.push_back(nums2[a]);
      }
    } else if(a<nums1.size())
      v.push_back(nums1[a]);
      else if(b< nums2.size())
      v.push_back(nums2[b]);
  }
  int median;
  if(!(nums1.size() + nums2.size())%2){
    median = v[middle];
  } else {
    median = (v[middle-1] + v[middle])/2.0;
  }

  return median;

}

int main ()
{
  int myints[] = {1, 2};
  vector<int> nums1(myints, myints + sizeof(myints) / sizeof(int) );
  int myints2[] = {};
  vector<int> nums2(myints2, myints2 + sizeof(myints2) / sizeof(int) );

  cout << "ans: "<< findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
}
 