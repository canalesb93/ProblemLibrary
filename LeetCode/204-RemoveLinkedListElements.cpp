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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
  ListNode *pseudo_head = new ListNode(0);
  pseudo_head->next = head;
  ListNode *cur = pseudo_head;
  while(cur){
      if(cur->next && cur->next->val == val)   cur->next = cur->next->next;
      else    cur = cur->next;
  }
  return pseudo_head->next;
}

// [5, *5]

int main ()
{
  ListNode *l1 = new ListNode(3);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(4);
  l1->next->next->next = new ListNode(3);
  l1->next->next->next->next = new ListNode(5);

  ListNode *ans = removeElements(l1, 4);

  while(ans){
    cout << ans->val<< " ";
    ans = ans->next;
  }

  return 0;
}
 