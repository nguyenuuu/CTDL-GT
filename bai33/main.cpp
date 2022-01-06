#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<queue>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, u, G[Max][Max];
bool visited[Max];
int parent[Max];

void BFS(int start) {
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int u = q.front();
    visited[u] = true;
    q.pop();
    for(int i = 1; i <= n; i++) {
      if(!visited[i]) {
        q.push(i);
        visited[i] = true;
        parent[i] = u;
      }
    }
  }
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("cay.out", ios::out | ios::trunc);

  fin >> n >> u;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];
  
  BFS(u);
  fout << n << " " << n - 1 << endl;
  for(int i = 1; i <= n; i++) 
    if(i != u)
      fout << parent[i] << " " << i << endl;

  fin.close();
  fout.close();
  return 0;
}