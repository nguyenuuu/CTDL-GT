#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, m, u;
vector<int> G[Max], res;
bool visited[Max];

void DFS(int start) {
  res.push_back(start);
  visited[start] = true;
  for(auto v : G[start]) {
    if(!visited[v])
      DFS(v);
  }
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("cay.out", ios::out | ios::trunc);

  fin >> n >> m >> u;
  
  for(int i = 1; i <= m; i++) {
    int u, v;
    fin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }  

  DFS(u);
  fout << n << " " << n - 1 << "\n";
  for(int i = 0; i < res.size() - 1; i++) {
    fout << res[i] << " " << res[i + 1] << "\n";
  }
  
  fin.close();
  fout.close();
  return 0;
}