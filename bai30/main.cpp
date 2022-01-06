#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, u;
string s;
vector<int> G[Max], res;
bool visited[Max];

void stringToNumber(int k) {
  s.push_back(' ');
  string tmp;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == ' ') {
      G[k].push_back(stoi(tmp));
      tmp.clear();
    } else {
      tmp.push_back(s[i]);
    }
  }
}

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

  fin >> n >> u;
  getline(fin , s);
  for(int i = 1; i <= n; i++) {
    getline(fin, s);
    stringToNumber(i);
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