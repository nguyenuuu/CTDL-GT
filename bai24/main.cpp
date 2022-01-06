#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
struct EDGE {
  int u, v, w;
};
EDGE edge[Max];
vector<EDGE> res;
int n, m;
bool visited[Max];

EDGE canhkenhonhat() {
  EDGE tmp = {1, 1, INT_MAX};
  for(int i = 1; i <= n; i++) {
    if(visited[i]) {
      for(int j = 0; j < m; j++) {
        int u = edge[j].u;
        int v = edge[j].v;
        int w = edge[j].w;
        if((u == i && !visited[v] && w < tmp.w) || (v == i && !visited[u] && w < tmp.w)) {
          tmp = edge[j];
        }
      }
    }
  }
  return tmp;
}

void Prim(int start) {
  visited[start] = true;
  while(1) {
    EDGE tmp = canhkenhonhat();
    visited[tmp.u] = true;
    visited[tmp.v] = true;
    res.push_back(tmp);
    int mark = 1;
    for(int i = 1; i <= n; i++) {
      if(!visited[i]) {
        mark = 0;
        break;
      }
    }
    if(mark) break;
  }
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);

  fin >> n >> m;
  for(int i = 0; i < m; i++)  
    fin >> edge[i].u >> edge[i].v >> edge[i].w;

  Prim(1);
  int Min = 0;
  for(auto e : res) Min += e.w;
  fout << Min << "\n";
  for(auto e : res)
    fout << e.u << " " << e.v << "\n";

  fin.close();
  fout.close();
  return 0;
}