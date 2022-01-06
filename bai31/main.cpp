#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, m, u;
vector<int> G[Max];
bool visited[Max];
int parent[Max];

void BFS(int start) {
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int u = q.front();
    visited[u] = true;
    q.pop();
    for(auto v : G[u]) {
      if(!visited[v]) {
        visited[v] = true;
        q.push(v);
        parent[v] = u;
      }
    }
  }
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("cay.out", ios::out | ios::trunc);

  fin >> n >> m >> u;
  for(int i = 0; i < m; i++) {
    int u, v;
    fin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  BFS(u);
  fout << n << " " << n - 1 << "\n";
  for(int i = 1; i <= n; i++) {
    if(i != u)
      fout << parent[i] << " " << i << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}