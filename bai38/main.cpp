#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n, G[Max][Max], pOdd;

// Có duy nhất 2 đỉnh có bậc vào và ra khác nhau 1
bool semiEuler() {
  int inGreaterOut = 0, outGreaterIn = 0;
  for(int i = 1; i <= n; i++) {
    int in = 0, out = 0;
    for(int j = 1; j <= n; j++) {
      if(G[i][j])
        out++;
      if(G[j][i])
        in++;
    }
    if(abs(in - out) > 1)
      return false;
    if(in - out == 1)
      inGreaterOut++;
    if(out - in == 1) {
      outGreaterIn++;
      pOdd = i;
    }
  }
  if(inGreaterOut == 1 && outGreaterIn == 1) 
    return true;
  return false;
}

void cycleEuler() {
  vector<int> CE;
  stack<int> stack;
  stack.push(pOdd);
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
    }
  }
  for(int i = CE.size()- 1; i >= 0; i--)
    fout << CE[i] << " ";
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);

  fin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];
  
  if(!semiEuler()) {
    fout << "G khong la do thi nua Euler\n";
  } else {
    fout << "G la do thi nua Euler\n";
    cycleEuler();
  }

  fin.close();
  fout.close();
  return 0;
}