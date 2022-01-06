#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, arr[Max][Max], visited[Max];
int Min = 1e8;
vector<int> mark, res;

// hàm tính tổng các phần tử arr[i][v[i]]
int sum(vector<int> v) {
  int s = 0;
  for(int i = 0; i < v.size(); i++)
    s += arr[i][v[i]];
  return s;
}

// xét đến hàng thứ k
void solve(int k) {
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      mark.push_back(i);
      visited[i] = true;
      if(k == n - 1) {
        if(sum(mark) < Min) {
          res = mark;
          Min = sum(mark);
        }
        mark.pop_back();
        visited[i] = false;
      } else {
        solve(k + 1);
        mark.pop_back();
        visited[i] = false;
      }
    }
  }
}

int main() {
  fin.open("matran.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      fin >> arr[i][j];

  solve(0);
  fout << Min << "\n";
  for(int i = 0; i < res.size(); i++) {
    fout << i + 1 << " " << res[i] + 1 << " " << arr[i][res[i]] << "\n";
  }
  fin.close();
  fout.close();
  return 0;
}