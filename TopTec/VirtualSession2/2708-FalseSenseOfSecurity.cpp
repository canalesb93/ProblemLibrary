/*
FENDSVTSLHW.EDATS,EULAY
TRDNWPLOEF
NTTTGAZEJUIIGDUZEHKUE
QEWOISE.EIVCAEFNRXTBELYTGD.
?EJHUT.TSMYGW?EJHOT
DSU.XFNCJEVE.OE_UJDXNO_YHU?VIDWDHPDJIKXZT?E
ADAWEKHZN,OTEATWRZMZN_IDWCZGTEPION
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


using namespace std;

struct node{
  node* left;  //dash
  node* right; //dot

  char value;
};

node *root;

map<char, pair<string, int> > dictionary;

string morse = "";
int counter = 0;
stack<int> length;

node* init_node(char value){
  node *nptr = new node();
  // cout << nptr << " setting " << value << endl;
  nptr->value = value;
  return nptr;
}
  
void initialize_map(){
  //dictionary
  dictionary['A'] = make_pair(".-", 2);
  dictionary['H'] = make_pair("....", 4);
  dictionary['O'] = make_pair("---", 3);
  dictionary['V'] = make_pair("...-", 4);
  dictionary['B'] = make_pair("-...", 4);
  dictionary['I'] = make_pair("..", 2);
  dictionary['P'] = make_pair(".--.", 4);
  dictionary['W'] = make_pair(".--", 3);
  dictionary['C'] = make_pair("-.-.", 4);
  dictionary['J'] = make_pair(".---", 4);
  dictionary['Q'] = make_pair("--.-", 4);
  dictionary['X'] = make_pair("-..-", 4);
  dictionary['D'] = make_pair("-..", 3);
  dictionary['K'] = make_pair("-.-", 3);
  dictionary['R'] = make_pair(".-.", 3);
  dictionary['Y'] = make_pair("-.--", 4);
  dictionary['E'] = make_pair(".", 1);
  dictionary['L'] = make_pair(".-..", 4);
  dictionary['S'] = make_pair("...", 3);
  dictionary['Z'] = make_pair("--..", 4);
  dictionary['F'] = make_pair("..-.", 4);
  dictionary['M'] = make_pair("--", 2);
  dictionary['T'] = make_pair("-", 1);
  dictionary['G'] = make_pair("--.", 3);
  dictionary['N'] = make_pair("-.", 2);
  dictionary['U'] = make_pair("..-", 3);

  dictionary['_'] = make_pair("..--", 4);
  dictionary['.'] = make_pair("---.", 4);
  dictionary[','] = make_pair(".-.-", 4);
  dictionary['?'] = make_pair("----", 4);
}

void initialize_tree(){
  //start
  root = init_node('/');

  //right side level1
  root->right = init_node('E');
  //right side level2
  root->right->right = init_node('I');
  root->right->left = init_node('A');
  //right side level 3
  root->right->right->right = init_node('S');
  root->right->right->left = init_node('U');
  root->right->left->right = init_node('R');
  root->right->left->left = init_node('W');
  //right side level 4
  root->right->right->right->right = init_node('H');
  root->right->right->right->left = init_node('V');
  root->right->right->left->right = init_node('F');
  root->right->right->left->left = init_node('_');//..--

  root->right->left->right->right = init_node('L');
  root->right->left->right->left = init_node(',');//.-.-
  root->right->left->left->right = init_node('P');
  root->right->left->left->left = init_node('J');//.---
  
  //left side level1
  root->left = init_node('T');
  //left side level2
  root->left->right = init_node('N');
  root->left->left = init_node('M');
  //left side level 3
  root->left->right->right = init_node('D');
  root->left->right->left = init_node('K');
  root->left->left->right = init_node('G');
  root->left->left->left = init_node('O');
  //left side level 4
  root->left->right->right->right = init_node('B');
  root->left->right->right->left = init_node('X');
  root->left->right->left->right = init_node('C');
  root->left->right->left->left = init_node('Y');

  root->left->left->right->right = init_node('Z');//--..
  root->left->left->right->left = init_node('Q');
  root->left->left->left->right = init_node('.');//---.
  root->left->left->left->left = init_node('?');//----

  // cout << root->left->left->left->right->value << endl;
}

char find(int size){
  node *current = root;
  for(int i = 0; i < size; i++){
    if(morse[counter++] == '.'){
      current = current->right;
    } else {
      current = current->left;
    }
  }
  return current->value;

}

int main ()
{ 
  initialize_tree();
  initialize_map();

  string input;

  while(cin >> input){
    morse = "";
    counter = 0;
    pair<string, int> temp;
    for(int i = 0; i < input.size(); i++){
      temp = dictionary[input[i]];
      morse += temp.first;
      length.push(temp.second);
      // cout << temp.second;
    }

    while(!length.empty()){
      printf("%c", find(length.top()));
      length.pop();
    }
    printf("\n");
  }

  return 0;
}
