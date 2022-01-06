#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, k, arr[Max][Max];
bool visited[Max];
vector<int> mark;
vector<vector<int>> res;

// hàm tính tổng các phần tử arr[i][v[i]]
int sum(vector<int> v) {
  int s = 0;
  for(int i = 0; i < v.size(); i++)
    s += arr[i][v[i]];
  return s;
}

// xét đến hàng thứ t
void solve(int t) {
  for(int i = 0; i < n; i++) {
    if(!visited[i]) {
      mark.push_back(i);
      visited[i] = true;
      if(t == n - 1) {
        if(sum(mark) == k) 
          res.push_back(mark);
        mark.pop_back();
        visited[i] = false;
      } else {
        solve(t + 1);
        mark.pop_back();
        visited[i] = false;
      }
    }
  }
}

int main() {
  fin.open("matran.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n >> k;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      fin >> arr[i][j];

  solve(0);
  fout << res.size() << "\n";
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++) {
      fout << res[i][j] + 1 << " ";
    }
    fout << "\n";
  }
  fin.close();
  fout.close();
  return 0;
}