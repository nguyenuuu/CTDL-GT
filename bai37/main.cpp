#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, G[Max][Max], pOdd;
vector<int> CE;

bool semi_Euler() {
  int odd = 0;
  for(int i = 1; i <= n; i++) {
    int count = 0;
    for(int j = 1; j <= n; j++) {
      if(G[i][j])
        count++;
    }
    if(count % 2) {
      odd++;
      pOdd = i;
    }
  }
  if(odd == 2) return true;
  return false; 
}

void cycleEuler(int start) {
  stack<int> stack;
  stack.push(start);
  while(!stack.empty()) {
    int u = stack.top();
    int x = 1;
    while(!G[u][x] && x <= n) 
      x++;
    if(x > n) {
      CE.push_back(u);
      stack.pop();
    } else {
      stack.push(x);
      G[u][x] = 0;
      G[x][u] = 0;
    }
  }
  for(auto v : CE)
    fout << v << " ";
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];

  if(!semi_Euler()) {
    fout << "G khong la do thi nua Euler\n";
  } else {
    fout << "G la do thi nua Euler\n";
    cycleEuler(pOdd);
  }

  fin.close();
  fout.close();
  return 0;
}