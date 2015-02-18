/*
10 10
1 3
3 4
4 3
5 3
5 10
4 6
6 7
7 8
8 9
9 2
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<long> vl;
typedef vector<int> vi;
typedef vector<long long> vll;

int N, M;
int dfsNumberCounter, numSCC;
vector<vl> graph;
vi dfs_num, dfs_low, S, visited, contaminated;
vll routes;

void travel_graph(int start){
  int u; // current vertex
  queue<int> q;
  q.push(start);
  while(q.empty() == false){
    u=q.front();
    // cout << u+1 << " travel current" << endl;
    visited[u]=1;
    q.pop();
    for(int i = 0; i < graph[u].size(); i++){
      int v = graph[u][i];
      if(contaminated[v]!=1 && visited[v]!=1){
        // cout << "DFS at " << u+1 << " on " << v+1 << " with " << routes[v] << " routes " << endl;
        q.push(v);
        routes[v] += routes[u];
        // cout << "Vertex " << u+1 <<" adds to " << v + 1 << endl;
      }
    }
  }
}

void tarjanSCC(int u){
  // cout << u+1 << " current" << endl;
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.push_back(u);
  visited[u] = 1;
  for(int j = 0; j < graph[u].size(); j++){
    int v = graph[u][j];
    if(dfs_num[v] == UNVISITED){
      // cout << "DFS at " << u+1 << " adding " << v+1 << " to stack " << endl;

      tarjanSCC(v);
    }
    if(visited[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  // if(dfs_low[u] == dfs_num[u]){ //AFTER RECURSION
  //   cout << "SCC " << ++numSCC << ":";
  //   while(1){
  //     int v = S.back(); S.pop_back(); visited[v] = 0;
  //     cout << " " << v+1;
  //     if(u == v) break;
  //   }
  //   cout << endl;
  // }
}

// void dfs(int u){
//   dfs_num[u] = VISITED;
//   cout << u+1 << " visited." << endl;
//   for(int j = 0; j < graph[u].size(); j++){
//     int v = graph[u][j];
//     if(dfs_num[v] == UNVISITED)
//       dfs(v);
//   }
// }

void print_last_nine(long long w);
void print_graph();

int main ()
{ 
  cin >> N >> M;

  graph.assign(N, vl());
  dfs_num.assign(N, UNVISITED);
  dfs_low.assign(N, 0);
  visited.assign(N, 0);
  contaminated.assign(N, 0);
  routes.assign(N, 0);
  routes[0]=1;
  dfsNumberCounter = numSCC = 0;

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    graph[a-1].push_back(b-1);
  }

  // print_graph();
  tarjanSCC(0);

  for(int i = 0; i < S.size(); i++){
    int vertex = S[i];
    if(contaminated[vertex]){
      // cout << vertex+1 << " contaminated c." << endl;
      for(int j = 0; j < graph[vertex].size();j++){
        contaminated[graph[vertex][j]]=1;
      }
    } else if((dfs_low[vertex] == dfs_low[vertex+1] || dfs_low[vertex] == dfs_low[vertex-1]) && i != 0 ){
      // cout << vertex+1 << " contaminated." << endl;
      for(int j = 0; j < graph[vertex].size();j++){
        contaminated[graph[vertex][j]]=1;
      }
      contaminated[vertex]=1;
    }
  }

  visited.assign(N, 0);
  travel_graph(0);

  // cout << "==========================" << endl;
  // print_graph();
  // print_last_nine(test);

  if(contaminated[1]){
    cout << "inf" << endl;
  } else if(routes[1]>999999999){
    print_last_nine(routes[1]);
  } else{
    cout << routes[1] << endl;
  }


  return 0;
}

// =============================================================================




void print_last_nine(long long w){
  int length = 1;
  long long x=w%1000000000;
  while ( x /= 10 )
    length++;
  for(int i = 0; i < 9-length; i++){
    cout << 0;
  }
  cout << w%1000000000 << endl;//missing check
}

void print_graph(){
  for(int i = 0; i < N; i++){
    // if(processed[i])
    //   cout << "P  ";
    // else
    //   cout << "nP ";
    // if(contaminated[i])
    //   cout << "C  ";
    // else
    //   cout << "nC ";
    cout << i+1 << "<" << routes[i] << ">" << ": ";
    for(int j=0; j < graph[i].size(); j++ ){
      cout << graph[i][j]+1 << " ";
    }
    cout << endl;
  }
}