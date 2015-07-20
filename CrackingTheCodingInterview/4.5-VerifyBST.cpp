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
#include <limits>

 
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkBST(TreeNode *current, int min, int max){
  if(current == NULL) return true;

  if(current->val <= min || current->val > max)
    return false;

  if(!checkBST(current->left, min, current->val) || !checkBST(current->right, current->val, max))
    return false;

  return true;

}

int main ()
{
  TreeNode *t1 = new TreeNode(10);
  t1->left = new TreeNode(5);
  t1->left->right = new TreeNode(7);
  t1->left->left = new TreeNode(2);
  t1->left->left->right = new TreeNode(3);

  t1->right = new TreeNode(15);
  t1->right->left = new TreeNode(12);
  t1->right->right = new TreeNode(17);
  t1->right->left->right = new TreeNode(13);

  // TreeNode *t2 = new TreeNode(15);
  // t2->left = new TreeNode(12);
  // t2->right = new TreeNode(17);
  // t2->left->right = new TreeNode(13);

  cout << "Is valid? " << checkBST(t1, numeric_limits<int>::min(), numeric_limits<int>::max()) << endl;

  return 0;
}
 