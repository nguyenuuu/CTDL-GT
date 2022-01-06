/*
Đề đã cho là liên thông yếu => không kiểm tra
Euler nếu tất cả các đỉnh có bậc vào bằng bậc ra
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
using namespace std;
fstream fin;
const int Max = 100;
int n, G[Max][Max];
vector<int> CE;

bool Euler() {
  for(int i = 1; i <= n; i++) {
    int in = 0, out = 0;
    for(int j = 1; j <= n; j++) {
      out += G[i][j];
      in += G[j][i];
    }
    if(in != out)
      return false;
  }
  return true;
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
    }
  }
}

int main() {
  fin.open("dothi.in", ios::in);

  fin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];
  
  if(!Euler()) {
    cout << "G khong la do thi Euler";
  } else {
    cout << "G la do thi Euler\n";
    int u;
    cin >> u;
    cycleEuler(u);
    for(int i = CE.size() - 1; i >= 0; i--) {
      cout << CE[i] << " ";
    }
  }

  fin.close();
  return 0;
}