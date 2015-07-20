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

bool matchTree(TreeNode *t1, TreeNode *t2){
  if(t1 == NULL || t2 == NULL){
    if(t1 == t2)
      return true;
    else
      return false;
  }
  if(t1->val != t2->val)
    return false;

  return matchTree(t1->left, t2->left) && matchTree(t1->right, t2->right);
}

bool subTree(TreeNode *t1, TreeNode *t2){
  if(!t1) return false;

  if(t1->val == t2->val){
    if(matchTree(t1, t2)) return true;
  }

  return (subTree(t1->left, t2) || subTree(t1->right, t2));
}

bool containsTree(TreeNode *t1, TreeNode *t2){
  if(!t2){
    return true;
  }

  return subTree(t1, t2);
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
  t1->right->left->left = new TreeNode(11);
  t1->right->right = new TreeNode(17);
  t1->right->left->right = new TreeNode(13);

  TreeNode *t2 = new TreeNode(15);
  t2->left = new TreeNode(12);
  t2->left->left = new TreeNode(11);
  t2->right = new TreeNode(17);
  t2->left->right = new TreeNode(13);

  cout << "Is subtree? " << containsTree(t1, t2) << endl;

  return 0;
}
 