#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<queue>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, k;
int G[Max][Max];
bool visited[Max];
int parent[Max];

//  vì số cable đi ra hay đi vào là nhiều nhất => dùng BFS
void BFS() {
  queue<int> q;
  q.push(k);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = true;
    for(int i = 1; i <= n; i++) {
      if(G[u][i] && !visited[i]) {
        q.push(i);
        visited[i] = true;
        parent[i] = u;
      }
    }
  }
} 

int main() {
  fin.open("mang.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  
  fin >> n >> k;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];

  BFS();
  fout << n << " " << n - 1 << "\n";
  for(int i = 1; i <= n; i++) {
    if(i != k) {
      fout << parent[i] << " " << i << "\n";
    }
  }

  fin.close();
  fout.close();
  return 0;
}