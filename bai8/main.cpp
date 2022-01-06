/*
  xi = 0 || xi = 1
  => Chọn dãy con của ai để tổng <= b; đồng thời tương ứng với các chỉ sổ của i thì tổng dãy con của ci là lớn nhất
*/

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
fstream fin, fout;
int n, b, a[100], c[100];
int Max = -1e8;
int arrayRes[100];
vector<int> mark, res;

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
    if(sumOfVector(mark, a) <= b) {
      if(sumOfVector(mark, c) > Max) {
        Max = sumOfVector(mark, c);
        res = mark;
      }
      solve(i + 1);
    }
    mark.pop_back();
  }
}

int main() {
  fin.open("data.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n >> b;
  for(int i = 0; i < n; i++)
    fin >> c[i];
  for(int i = 0; i < n; i++)
    fin >> a[i];
  
  solve(0);
  fout << Max << "\n";
  for(int i = 0; i < res.size(); i++)
    arrayRes[res[i]] = 1;
  for(int i = 0; i < n; i++)
    fout << arrayRes[i] << " ";
    
  fin.close();
  fout.close();
  return 0;
}