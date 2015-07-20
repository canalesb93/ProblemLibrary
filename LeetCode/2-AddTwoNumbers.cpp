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
 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  int carry = 0, current_sum;

  ListNode *head = NULL, **ans = &head;


  while(l1 || l2){
    int x = 0, y = 0;
    if(l1) x = l1->val;
    if(l2) y = l2->val;

    current_sum = x + y;
    current_sum += carry;

    carry = current_sum/10;
   
    ListNode *node = new ListNode(current_sum%10);
    *ans = node;
    ans = (&node->next);

    if(l1) l1=l1->next;
    if(l2) l2=l2->next;
  }
  if(carry>0)
    *ans = new ListNode(carry);
  return head;

}

int main ()
{

  ListNode *l1 = new ListNode(5);
  l1->next = new ListNode(4);
  // l1->next->next = new ListNode(3);
  
  ListNode *l2 = new ListNode(5);
  // l2->next = new ListNode(6);
  // l2->next->next = new ListNode(4);

  ListNode *ans = addTwoNumbers(l2, l1);
  while(ans){
    cout << ans->val<< " ";
    ans = ans->next;
    
  }
  return 0;
}
