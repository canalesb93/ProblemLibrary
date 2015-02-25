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
#include <sstream>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
  if(p == NULL && q == NULL)
    return true;
  else if(p == NULL || q == NULL)
    return false;
  if(p->val != q->val)
    return false;



  bool left = false, right = false, equal = false;    
  left = isSameTree(p->left, q->left);
  right = isSameTree(p->right, q->right);

  return left && right;
}

int main ()
{
  TreeNode *root1 = new TreeNode(5);
  root1->right = new TreeNode(2);
  root1->right->right = new TreeNode(7);
  root1->left = new TreeNode(4);


  TreeNode *root2 = new TreeNode(5);
  root2->right = new TreeNode(2);
  root2->right->right = new TreeNode(7);
  // root2->left = new TreeNode(4);
  root2->left = new TreeNode(2);

  cout << isSameTree(root1, root2) << endl;
  // cout << root->val << endl;
  // cout << root->right->val << endl;
  return 0;
}
