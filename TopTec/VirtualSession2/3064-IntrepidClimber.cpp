/*
6 2
1 2 2
2 4 2
1 3 3
3 6 3
3 5 1
5 2
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

int N, F;
vector<vector<pair<int, int> > > v;
vector<bool> safe, discovered;
vector<int> parent, friends;

void setsafe(int v){
  if(v == 0)
    return;
  safe[v] = true;
  if(!safe[parent[v]]){
    cout << "TEST" << endl;
    setsafe(parent[v]);
  }
}

void dfs(int vertex) { 
  int successor; /* successor vertex */ 
  discovered[vertex] = true;
  printf("%d ", vertex+1);
  // process_vertex(v);
  for (int i=0; i<v[vertex].size(); i++) {
    successor = v[vertex][i].first;
    if (discovered[successor] == false) {
      parent[successor] = vertex;
      dfs(successor);
    }
  } 
  // safe[vertex] = true;
  return;
}

int main ()
{


  cin >> N >> F;

  safe.assign(N, false); 
  discovered.assign(N, false); 
  parent.assign(N, -1); 
  safe[0] = true;

  v.assign(N, vector<pair<int, int> >());

  // Input of Edges and Weights
  for(int i = 0; i < N-1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    v[a-1].push_back(make_pair(b-1, c));
  }

  //Input of friends
  for(int i = 0; i < F; i++){
    int f;
    cin >> f;
    safe[f-1] = true;
    friends.push_back(f-1);
  }

  dfs(0);
  printf("\n");
  
  printf("parents: ");  
  for(int i = 0 ; i < parent.size();i++)
    printf("%d ", parent[i]);


  cout << "par" << parent[2];
  printf("\n");
  for(int i = 0; i < friends.size(); i++){
    setsafe(parent[friends[i]]);
  }


  for(int i = 0; i < parent.size(); i++){
    cout << i+1 << " is: " << safe[i] << endl;
  }

  // cout << "Hello World!" << endl;  
  return 0;
}
