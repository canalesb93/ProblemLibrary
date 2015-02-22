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

int maxDepth(TreeNode *root) {
  if(root == NULL){
    return 0;
  }
  int left, right;

  left = maxDepth(root->left);
  right = maxDepth(root->right);

  return left > right ? left + 1 : right + 1;
} 

int main ()
{
  TreeNode *root = new TreeNode(5);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(7);
  root->left = new TreeNode(4);

  cout << maxDepth(root) << endl;
  // cout << root->val << endl;
  // cout << root->right->val << endl;
  return 0;
}
