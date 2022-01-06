#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, b, a[Max];
int arrayRes[Max];
vector<int> mark;
vector<vector<int>> res;

int sumOfVector(vector<int> v, int *array) {
  int sum = 0;
  for(int i = 0; i < v.size(); i++) 
    sum += array[v[i]];
  return sum;
}

// xét đến phần tử thứ t của mảng a
void solve(int t) {
  for(int i = t; i < n; i++) {
    mark.push_back(i);
    if(sumOfVector(mark, a) == b) {
      res.push_back(mark);
      mark.pop_back();
    } else {
      solve(i + 1);
      mark.pop_back();
    }
  }
}

int main() {
  fin.open("data.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n >> b;
  for(int i = 0; i < n; i++)
    fin >> a[i];
  
  solve(0);

  fout << res.size() << "\n";
  for(int i = 0; i < res.size(); i++) {
    memset(arrayRes, 0, sizeof(arrayRes));
    for(int j = 0; j < res[i].size(); j++) {
      arrayRes[res[i][j]] = 1;
    }
    for(int i = 0; i < n; i++)
      fout << arrayRes[i] << " ";
    fout << "\n";
  }
    
  fin.close();
  fout.close();
  return 0;
}