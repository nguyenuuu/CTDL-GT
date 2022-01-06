#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
const int Min = -1e8;
const int Max = 100;
fstream fin, fout;
int n, k, arr[Max];
vector<int> mark;
vector<vector<int>> res;

// vị trí thứ t trong mảng
void solve(int t) {
  for(int i = t; i < n; i++) {
    // kiểm tra xem phần tử trong mảng đg xét có lớn hơn phần tử cuối cùng trong mark hay k
    if(arr[i] > mark[mark.size() - 1]) {
      mark.push_back(arr[i]);
      if(mark.size() == k + 1) {
        res.push_back(mark);
        mark.pop_back();
      } else {
        solve(i + 1);
        mark.pop_back();
      }
    }
  }
}

int main() {
  fin.open("dayso.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n >> k;
  for(int i = 0; i < n; i++)
    fin >> arr[i];

  // Chèn phần tử nhỏ vô cùng vào mark
  mark.push_back(Min);
  solve(0);
  fout << res.size() << "\n";
  for(int i = 0; i < res.size(); i++) {
    for(int j = 1; j < res[i].size(); j++) {
      fout << res[i][j] << " ";
    }
    fout << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}