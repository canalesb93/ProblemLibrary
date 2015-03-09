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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  ListNode *newList = new ListNode(-1);
  ListNode *tail = newList;

  while(l1 && l2){
    if(l1->val < l2->val){
      tail->next = l1;
      l1 = l1->next;
    } else {
      tail->next = l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }
  tail->next = l1 ? l1 : l2;
  return newList->next;

}

int main ()
{

  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(3);
  l1->next->next = new ListNode(4);
  
  ListNode *l2 = new ListNode(0);
  l2->next = new ListNode(4);
  l2->next->next = new ListNode(6);

  ListNode *ans = mergeTwoLists(l1, l2);
  while(ans){
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;

  return 0;
}
