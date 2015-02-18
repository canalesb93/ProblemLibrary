/*

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
typedef map<int, long> mil;

int N, K;
vector<vl> graph;
vi visited;
mil map;

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

void print_last_nine(long long w);
void print_graph();

int main ()
{ 
  cin >> N >> K;

  graph.assign(N, vl());

  for(int i = 0; i < N; i++){
    int aw, b;
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