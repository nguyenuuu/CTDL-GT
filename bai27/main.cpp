#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, work[Max][Max];
int Min = 1e8;
bool visited[Max];
vector<int> mark, res;

int sumOfMark() {
  int res = 0;
  for(int i = 0; i < mark.size(); i++) {
    res += work[i + 1][mark[i]];
  }
  return res;
}

void solve(int t) {
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      mark.push_back(i);
      visited[i] = true;
      if(t == n) {
        if(sumOfMark() < Min) {
          Min = sumOfMark();
          res = mark;
        }
      } else {
        solve(t + 1);
      }
      mark.pop_back();
      visited[i] = false;
    }
  } 
}

int main() {
  fin.open("viec.inp", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> work[i][j];

  solve(1);
  fout << Min << "\n";
  for(int i = 0; i < res.size(); i++)
    fout << res[i] << " ";

  fin.close();
  fout.close();
  return 0;
}