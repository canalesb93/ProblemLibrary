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


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  ListNode *aux1 = head;
  ListNode *aux2 = head;
  if(head == NULL)
    return false;

  while(aux1 != NULL && aux2 != NULL){
    aux1 = aux1->next;
    if(aux2->next == NULL)
      return false;
    aux2 = aux2->next->next;
    if(aux1 == aux2)
      return true;
  }
  return false;

}

int main ()
{
  ListNode *root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(2);
  root->next->next->next = new ListNode(2);
  root->next->next->next->next = root->next;
  cout << hasCycle(root) << endl;
  return 0;
}
