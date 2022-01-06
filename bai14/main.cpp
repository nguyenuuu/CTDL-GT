#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<cstring>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n;
int **G;
int tplt[Max];
int tpltBandau;
vector<int> res;

void BFS(int** matrix, int start, int count) {
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    tplt[u] = count;
    for(int i = 0; i < n; i++) {
      if(!tplt[i] && matrix[u][i]) {
        q.push(i);
        tplt[i] = count;
      }
    }
  }
}

int soTPLT(int** matrix) {
  int count = 1;
  memset(tplt, 0, sizeof(tplt));
  for(int i = 0; i < n; i++) {
    if(!tplt[i]) {
      BFS(matrix, i, count);
      count++;
    }
  }
  return count - 1;
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("dinhtru.out", ios::out | ios::trunc);
  fin >> n;
  G = new int *[n];
  for (int i = 0; i < n; i++)
    G[i] = new int [n];

  for(int i = 0; i < n; i++) 
    for(int j = 0; j < n; j++) 
      fin >> G[i][j];
    
  tpltBandau = soTPLT(G);
  
  for(int i = 0; i < n; i++) {
    int** matrix = new int *[n];
    for(int j = 0; j < n; j++)
      matrix[j] = new int[n];

    for(int x = 0; x < n; x++) {
      for(int y = 0; y < n; y++) {
        if(x != i && y != i) {
          matrix[x][y] = G[x][y];
        } else {
          matrix[x][y] = 0;
        }
      }
    }
    // có +1 vì số thành phần liên thông của matrix đang tính cả đỉnh bỏ đi
    if(soTPLT(matrix) > tpltBandau + 1) {
      res.push_back(i);
    }
  }

  fout << res.size() << "\n";
  for(int i = 0; i < res.size(); i++)
    fout << res[i] + 1 << " ";
    
  fin.close();
  fout.close();
  return 0;
}