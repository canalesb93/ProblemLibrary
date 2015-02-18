/*
Hello World!
*/
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

node root;

node findNode(int val){
  node nodeAux = root;
  if(root == NULL){
    return NULL;
  }
  while(nodeAux->next != NULL){
    if(nodeAux->next->value == val)
      return nodeAux->next;
    else{
      nodeAux = nodeAux->next
    }
  }
  return NULL;
}

void eraseNode(int val){
  node nodeAux = root;
  if(root == NULL){
    return
  }
  while(nodeAux->next != NULL){
    if(nodeAux->next->value == val){
      node toDelete = nodeAux->next;
      nodeAux->next = toDelete->next;
      delete toDelete;
    }
  }
  return
}



int main ()
{
  node value = findNode(10);

  cout << "Hello World!" << endl;
  return 0;
}
