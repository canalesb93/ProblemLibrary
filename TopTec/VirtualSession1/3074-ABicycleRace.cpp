/*
6 7
1 3
1 4
3 2
4 2
5 6
6 5
3 4



*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<long> > v;
vector<long> weight;
vector<bool> processed, discovered;
queue<long> contaminate;

void print_last_nine(long w){
  int length = 1;
  long x=w%1000000000;
  while ( x /= 10 )
    length++;
  for(int i = 0; i < 9-length; i++){
    cout << 0;
  }
  cout << w%1000000000 << endl;//missing check
}

void print_graph(){
  for(int i = 0; i < N; i++){
    if(processed[i])
      cout << "P  ";
    else
      cout << "nP ";
    if(contaminated[i])
      cout << "C  ";
    else
      cout << "nC ";
    cout << i+1 << "<" << weight[i] << "> ["<< processed[i] << "]" << ": ";
    for(int j=0; j < v[i].size(); j++ ){
      cout << v[i][j]+1 << " ";
    }
    cout << endl;
  }
}

void travel_graph(int start){
  int vertex; // current vertex
  queue<int> q;
  q.push(start);
  while(q.empty() == false){
    vertex=q.front();
    q.pop();
    processed[vertex] = true;
    for(int i = 0; i < v[vertex].size(); i++){
      if(processed[v[vertex][i]]==false){
        q.push(v[vertex][i]);
        weight[v[vertex][i]] += weight[vertex];
        // cout << "Vertex " << vertex+1 <<" adds to " << v[vertex][i] + 1 << endl;
      } else if(processed[v[vertex][i]]==true && v[v[vertex][i]].size()>0){
        // cout << "LOOP AT: " << vertex+1 << " and " << v[vertex][i]+1 << endl;
        weight[v[vertex][i]]=-100;
        q.push(v[vertex][i]);
      }
    }
  }
}

// ==============================================
void dfs(int vertex) { 
  int successor; /* successor vertex */ 
  discovered[vertex] = TRUE;
  // process_vertex(v);
  for (int i=0; i<v[vertex].size(); i++) {
    successor = v[vertex][i];
    if (discovered[successor] == FALSE) {
      parent[successor] = v;
      dfs(g,successor);
    } else if (processed[successor] == TRUE) cout << "Contaminated at " << successor+1 << endl;
  } 
  processed[v] = TRUE;
  return;
}


// ==============================================

int main ()
{ 
  cin >> N >> M;
  // int graph_adjency[N+1][N+1];
  // for(int i = 0;i < N;i++)
  //   for(int j = 0; j < N; j++)
  //     graph_adjency[i][j]=0;



  v.assign(N, vector<long>());
  weight.assign(N, 0);
  weight[0] = 1;
  processed.assign(N, false); 
  discovered.assign(N, false); 
  contaminated.assign(N, false); 
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    // if(graph_adjency[a-1][b-1]==0){
      v[a-1].push_back(b-1);
      // graph_adjency[a-1][b-1]+=1;
    // }
  }

  // print_graph();
  travel_graph(0);
  // cout << "====================" << endl;
  // print_graph();
  if(weight[1]<0){
    cout << "inf" << endl;
  } else if(weight[1]>999999999){
    print_last_nine(weight[1]);
  } else{
    cout << weight[1] << endl;
  }

  // cout << "====================" << endl;
  // long long test = 1000999008;

  return 0;
}
