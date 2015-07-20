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
// #include <queue>
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
  Node(int x) : val(x), next(0) {}
};

class Queue {
  public:
    Node *front, *back;
    Queue() : front(NULL), back(NULL) {}
    ~Queue(){
      while(front != NULL) dequeue();
    }

    void enqueue(int x){ // enqueue
      if(!front){
        back = new Node(x);
        front = back;
      } else {
        back->next = new Node(x);
        back = back->next;
      }
    }

    int dequeue(){
      if(!front) throw "Stack empty.";
      Node *t = front;
      int val = front->val;
      front = front->next;
      delete t;
      return val;
    }

    bool empty(){
      if(!front) return true;
      return false;
    }

};

int main ()
{
  Queue myQueue;
  myQueue.enqueue(4);
  myQueue.enqueue(3);
  myQueue.enqueue(2);
  myQueue.enqueue(1);

  while(!myQueue.empty()){
    cout << myQueue.dequeue() << " ";
  }



  return 0;
}
 