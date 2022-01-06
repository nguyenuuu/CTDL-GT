#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, k, b;
int arr[Max];
vector<int> mark;
vector<vector<int>> res;

void solve(int t, int sum, int Size) {
  for(int i = t; i < n; i++) {
    mark.push_back(arr[i]);
    if(Size == k) {
      if(sum + arr[i] == b) {
        res.push_back(mark);
      }
      mark.pop_back();
    } else {
      solve(i + 1, sum + arr[i], Size + 1);
      mark.pop_back();
    }
  }
}

int main() {
  fin.open("dayso.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n >> k >> b;
  for(int i = 0; i < n; i++) 
    fin >> arr[i];

  solve(0, 0, 1);
  fout << res.size() << "\n";
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++) {
      fout << res[i][j] << " ";
    }
    fout << "\n";
  }
  fin.close();
  fout.close();
  return 0;
}