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
  char val;
  ListNode *next;
  ListNode(char x) : val(x), next(NULL) {}
};


char toHighercase(char c){
  if(c >= 'a'){
    c -= ('a' - 'A');
  }
  return c;
}

int getSize(ListNode *head){
  ListNode *temp = head;
  int size = 0;
  while(temp){
    size++;
    temp = temp->next;
  }
  return size;
}


// O(2n)
bool isPalindrome(ListNode *head){
  if(head == NULL) return false;
  if(head->next == NULL) return true;

  ListNode *node = head;
  stack<char> S;
  bool palindrome = true;

  int size = getSize(head);

  int current = 1;
  while(node){
    if(current <= size/2){

      S.push(toHighercase(node->val));

    } else if(current > (size/2) + (size%2)){
      if(S.empty() || S.top() == toHighercase(node->val)){
        S.pop();
      } else {
        palindrome = false; 
        break;
      }
    }
    current++;
    node = node->next;
  }
  return palindrome;
}

int main ()
{

  ListNode *l1 = new ListNode('M');
  l1->next = new ListNode('a');
  l1->next->next = new ListNode('a');
  l1->next->next->next = new ListNode('m');
  l1->next->next->next->next = new ListNode('A');
  l1->next->next->next->next->next = new ListNode('m');

  cout << "Is Palindrome: " << isPalindrome(l1) << endl;
  return 0;
}
 