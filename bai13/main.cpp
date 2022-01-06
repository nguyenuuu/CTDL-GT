#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<cstring>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n;
int G[Max][Max];
int tplt[Max];
int tpltBandau;
vector<pair<int, int>> edge;

void BFS(int start, int count) {
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    tplt[u] = count;
    for(int i = 0; i < n; i++) {
      if(!tplt[i] && G[u][i]) {
        q.push(i);
        tplt[i] = count;
      }
    }
  }
}

int soTPLT() {
  int count = 1;
  memset(tplt, 0, sizeof(tplt));
  for(int i = 0; i < n; i++) {
    if(!tplt[i]) {
      BFS(i, count);
      count++;
    }
  }
  return count - 1;
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("canhcau.out", ios::out | ios::trunc);
  fin >> n;
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < n; j++) 
      fin >> G[i][j];
    
  tpltBandau = soTPLT();
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(G[i][j]) {
        G[i][j] = 0;
        G[j][i] = 0;
        if(soTPLT() > tpltBandau) {
          edge.push_back({i, j});
        }
        G[i][j] = 1;
        G[j][i] = 1;
      }
    }
  }

  fout << edge.size() << "\n";
  for(auto v : edge) {
    fout << v.first + 1 << " " << v.second + 1 << "\n";
  }  

  fin.close();
  fout.close();
  return 0;
}