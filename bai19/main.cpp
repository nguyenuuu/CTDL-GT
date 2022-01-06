#include<iostream>
#include<vector>
#include<fstream>
#include<map>
using namespace std;
fstream fin, fout;

map<int, int> dathuc;

int main() {
  fin.open("dathuc1.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  int n;
  // đa thức 1
  fin >> n;
  for(int i = 0; i < n; i++) {
    int heso, somu;
    fin >> heso >> somu;
    dathuc[somu] += heso;
  }
  fin.close();
  fin.open("dathuc2.in", ios::in);
  // đa thức 2
  fin >> n;
  for(int i = 0; i < n; i++) {
    int heso, somu;
    fin >> heso >> somu;
    dathuc[somu] += heso;
  }

  fout << dathuc.size() << "\n";
  // rbegin và rend để in ngược lại
  for(auto itr = dathuc.rbegin(); itr != dathuc.rend(); itr++) {
    fout << itr->second << "  " << itr->first << "\n";
  }

  fout.close();
  return 0;
}