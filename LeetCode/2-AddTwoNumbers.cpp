/*
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int getAndMove(ListNode* &l){
  int x = 0;
  if(l != NULL){
    x = l->val;
    l = l->next;
  }
  return x;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  int a = 0, b = 0, c = 0, carry = 0;
  ListNode *head = NULL, **ans = &head;

  while(l1 != NULL || l2 != NULL){
    a = getAndMove(l1);
    b = getAndMove(l2);
    c = a + b + carry;

    ListNode *node = new ListNode(c%10);
    *ans = node;
    ans = (&node->next);

    carry = c/10;
  }
  if(carry > 0){
    ListNode *node = new ListNode(carry);
    *ans = node;
  }
  return head;
}

int main ()
{

  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(8);
  // l1->next->next = new ListNode(3);
  
  ListNode *l2 = new ListNode(0);
  // l2->next = new ListNode(6);
  // l2->next->next = new ListNode(4);

  ListNode *ans = addTwoNumbers(l2, l1);
  cout << ans->val;
  cout << ans->next->val;
  // cout << ans->next->next->val;
  cout << endl;

  return 0;
}
