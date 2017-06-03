/*
10
2 1 2
1 5
1 3
2 4 9
2 7 6
1 6
0
1 8
0
1 8
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

vector<int> ts;
vector<bool> visited_ts;
vector<bool> visited;
vector<vector<int> > graph;

int total;

void print_graph(){
  for(int i = 0; i < graph.size(); i++){
    cout << "Node " << i << ": ";
    for(int j = 0; j < graph[i].size();j++){
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}

void dfs_ts(int node){
  visited_ts[node] = true;
  for(int i = 0; i < graph[node].size(); i++){
    if(visited_ts[graph[node][i]] == false){
      dfs_ts(graph[node][i]);
    }
  }
  ts.push_back(node);
}

void dfs(int node){
    visited[node] = true;
    for(int i = 0; i < graph[node].size(); i++){
        if(visited[graph[node][i]] == false){
            dfs(graph[node][i]);
            break;
        }
    }
}

int main ()
{

  int n;
  cin >> n;
  total = 0;
  graph = vector<vector<int> >(n);
  visited_ts = vector<bool>(n, false);
  visited = vector<bool>(n, false);

  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    for(int j = 0; j < k; j++){
      int connection;
      cin >> connection;
      graph[i].push_back(connection);
    }
  }

  print_graph();

  ts.clear();
  cout << "TOP SORT: ";
  for(int i = 0; i < n; i++){
    cout << i << " --> ";
    if(visited_ts[i] == false)
      dfs_ts(i);
  }
  cout << endl;

  for(int i = ts.size()-1; i >= 0 ; i--){
    if(!visited[ts[i]]) {
        dfs(ts[i]);
        total++;
    }
  }
  cout<<total<<endl;




  return 0;
}