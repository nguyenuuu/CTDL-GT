#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
fstream fin, fout;
const int Max = 100;
int dMax = -1e8;
int n, G[Max][Max];
bool visted[Max];
vector<int> mark, res;

int sumOfMark() {
  int res = 0, Size = mark.size();
  for(int i = 0; i < Size - 1; i++) {
    res += G[mark[i]][mark[i + 1]];
  }
  return res + G[mark[Size - 1]][1];
}

void solve(int t) {
  for(int i = 1; i <= n; i++) {
    if(!visted[i]) {
      mark.push_back(i);
      visted[i] = true;
      // n - 1 vì đỉnh 1 đã đi dầu tiên
      if(t == n - 1) {
        if(dMax < sumOfMark()) {
          dMax = sumOfMark();
          res = mark;
        }
        mark.pop_back();
        visted[i] = false;
      } else {
        solve(t + 1);
        mark.pop_back();
        visted[i] = false;
      }
    }
  }
}

int main() {
  fin.open("chiphi.in", ios::in);
  fout.open("cucdai.out", ios::out | ios::trunc);

  fin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];
  
  // đỉnh 1 được đi đầu tiên
  mark.push_back(1);
  visted[1] = true;
  solve(1);
  fout << dMax << "\n";
  // thêm 1 vào để thành 1 chu trình
  res.push_back(1);
  for(int i = 0; i < res.size(); i++) 
    fout << res[i] << " ";

  fin.close();
  fout.close();
  return 0;
}