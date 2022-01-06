#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, k;
int G[Max][Max];
bool visited[Max];
vector<int> res;

//  vì số cable đi ra hay đi vào là nhỏ nhất => dùng DFS
void DFS(int u) {
  res.push_back(u);
  visited[u] = true;
  if(res.size() == n) 
    return;
  for(int i = 0; i < n; i++) {
    if(!visited[i] && G[u][i]) {
      DFS(i);
    }
  }
  visited[u] = true;
}

int main() {
  fin.open("mang.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  
  fin >> n >> k;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      fin >> G[i][j];

  DFS(k - 1);
  fout << n << " " << res.size() - 1 << "\n";
  for(int i = 0; i < res.size() - 1; i++) 
    fout << res[i] + 1 << " " << res[i + 1] + 1 << "\n";

  fin.close();
  fout.close();
  return 0;
}