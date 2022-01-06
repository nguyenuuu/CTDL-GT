#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, countEdge;
string s;
vector<int> G[Max];

void stringToNumber(int k) {
  s.push_back(' ');
  string tmp;
  for(auto c : s) {
    if(c == ' ') {
      G[k].push_back(stoi(tmp));
      tmp.clear();
    } else {
      tmp.push_back(c);
    }
  }
}

int main() {
  fin.open("dske.in", ios::in);
  fout.open("mtke.out", ios::out | ios::trunc);

  fin >> n;
  getline(fin, s);
  for(int i = 1; i <= n; i++) {
    getline(fin, s);
    stringToNumber(i);
  }
  // Ghi ra file mtke.out
  fout << n << "\n";
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(find(G[i].begin(), G[i].end(), j) != G[i].end()) {
        fout << 1 << " ";
        countEdge++;
      }
      else 
        fout << 0 << " ";
    }
    fout << "\n";
  }
  fin.close();
  fout.close();
  fout.open("dscanh.out", ios::out | ios::trunc);
  fout << n << " " << countEdge << '\n';
  for(int i = 1; i <= n; i++) 
    for(auto v : G[i]) 
      fout << i << " " << v << "\n";
  
  fout.close();
  return 0;
}