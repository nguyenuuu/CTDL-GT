#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, G[Max][Max];
bool visited[Max];
vector<int> mark;
vector<vector<int>> res;

void solve(int t) {
  for(int i = 1; i <= n; i++) {
    if(!visited[i] && G[t][i]) {
      mark.push_back(i);
      visited[i] = true;
      if(mark.size() == n) {
        if(G[mark[mark.size() - 1]][1]) {
          res.push_back(mark);
        }
        mark.pop_back();
        visited[i] = false;
      } else {
        solve(i);
        mark.pop_back();
        visited[i] = false;
      }
    }
  }
}

int main() {
  fin.open("data.in", ios::in);
  
  fin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];

  visited[1] = true;
  mark.push_back(1);  
  solve(1);
  cout << res.size() << "\n";
  for(int i = 0; i < res.size(); i++) {
    for(auto v : res[i]) {
      cout << v << " ";
    }
    cout << 1 << "\n";
  }

  fin.close();
  
  return 0;
}