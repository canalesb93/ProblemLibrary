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

ListNode* deleteDuplicates(ListNode* head) {
  if(!head) return NULL;
  if(!head->next) return head;

  int val = head->val;
  ListNode *temp = head->next;

  if(temp->val != val){
    head->next = deleteDuplicates(temp);
    return head;
  } else {
    while(temp && temp->val == val) temp = temp->next;
    return deleteDuplicates(temp);
  }

}

int main ()
{

  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(1);
  l1->next->next = new ListNode(2);
  l1->next->next->next = new ListNode(3);
  l1->next->next->next->next = new ListNode(3);
  l1->next->next->next->next->next = new ListNode(5);

  ListNode *ans = deleteDuplicates(l1);
  while(ans){
    cout << ans->val<< " ";
    ans = ans->next;
    
  }
  return 0;
}
