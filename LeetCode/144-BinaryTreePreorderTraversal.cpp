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

 //   5
 //  / \
 // 4   2
 //  \
 //   7

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> ans;
  if(root == NULL)
    return ans;
  TreeNode *aux = root;
  stack<TreeNode *> s;
  s.push(root);
  while(!s.empty()){
    printf("%d\n", s.top()->val);
    ans.push_back(s.top()->val);
    aux = s.top();
    s.pop();
    if(aux->right != NULL)
      s.push(aux->right);
    if(aux->left != NULL)
      s.push(aux->left);
  }
  return ans;
}

int main ()
{
  TreeNode *root = new TreeNode(5);
  root->right = new TreeNode(2);
  root->left = new TreeNode(4);
  root->left->right = new TreeNode(7);

  preorderTraversal(root);
  // cout << root->val << endl;
  // cout << root->right->val << endl;
  return 0;
}
