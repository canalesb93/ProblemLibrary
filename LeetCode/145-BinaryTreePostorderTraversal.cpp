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

vector<int> postorderTraversal(TreeNode *root) {
  vector<int> ans;
  vector<TreeNode *> stack;
  if(root == NULL)
    return ans;
  TreeNode *aux = root;
  TreeNode *last = NULL;
  
  while(stack.size() > 0 || aux != NULL){

    if(aux != NULL){
      stack.push_back(aux);
      aux = aux->left;
    } else {
      TreeNode *back = stack.back();

      if(back->right != NULL && back->right != last){
        aux = back->right;
      } else {
        stack.pop_back();
        ans.push_back(back->val);
        printf("%d\n", back->val);
        last = back;
      }
    }
  }
  return ans;
}

vector<int> postorderTraversal2(TreeNode *root) {
  vector<int> a, b, ans;
  //fill with data

  if(root == NULL)
    return ans;
  a = postorderTraversal(root->left);
  ans.insert(ans.end(), a.begin(), a.end());
  b = postorderTraversal(root->right);
  ans.insert(ans.end(), b.begin(), b.end());

  ans.push_back(root->val);
  printf("%d\n", root->val);

  return ans;
}

int main ()
{
  TreeNode *root = new TreeNode(5);
  root->right = new TreeNode(2);
  root->left = new TreeNode(4);
  root->left->right = new TreeNode(7);
  root->left->right->left = new TreeNode(3);

  postorderTraversal(root);
  // cout << root->val << endl;
  // cout << root->right->val << endl;
  return 0;
}
