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

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkHeight(TreeNode *node){
  if(node == NULL)
    return 0;

  int leftHeight = checkHeight(node->left);
  int rightHeight = checkHeight(node->right);
  if(leftHeight == -1)
    return -1;
  if(rightHeight == -1)
    return -1;

  // current node
  if(abs(leftHeight - rightHeight) > 1){
    return -1;
  } else {
    return max(leftHeight, rightHeight) + 1;
  }

}

bool balanced(TreeNode *root){
  if(checkHeight(root) != -1)
    return true;
  else 
    return false;
}

int main ()
{

  TreeNode *t1 = new TreeNode(10);
  t1->left = new TreeNode(5);
  t1->left->right = new TreeNode(7);
  t1->left->left = new TreeNode(2);
  t1->left->left->left = new TreeNode(1);
  t1->left->left->right = new TreeNode(3);

  t1->right = new TreeNode(15);
  t1->right->left = new TreeNode(12);
  t1->right->right = new TreeNode(17);
  t1->right->left->right = new TreeNode(13);

  cout << "is balanced?: " << balanced(t1) << endl;

  return 0;
}
 