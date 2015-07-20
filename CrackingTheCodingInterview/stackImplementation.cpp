/*
Hello World!
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
// #include <stack>
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

struct Node {
  int val;
  Node *next;
  Node(int x, Node *n) : val(x), next(n) {}
};

class Stack {
  public:
    Node *front;
    Stack() : front(NULL) {}
    ~Stack(){
      while(front != NULL) pop();
    }

    Stack& push(int x){
      front = new Node(x, front);
      return *this;
    }

    int pop(){
      if(!front) throw "Stack empty.";
      Node *t = front;
      int val = front->val;
      front = front->next;
      delete t;
      return val;
    }

    int top(){
      return front->val;
    }

    bool empty(){
      if(front == NULL) return true;
      return false;
    }

};

int main ()
{
  Stack myStack;
  myStack.push(4);
  myStack.push(3);
  myStack.push(2);
  myStack.push(1);

  while(!myStack.empty()){
    cout << myStack.pop() << " ";
    // myStack.pop();
  }



  return 0;
}
 