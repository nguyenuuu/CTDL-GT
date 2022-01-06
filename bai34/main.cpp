/*
  Vì đề bài đã cho là đồ thị vô hướng liên thông nên không phải kiểm tra tính liên thông của đồ thị
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

// Đồ thị Euler nếu bậc các đỉnh đều chẵn
bool Euler() {
  for(int i = 1; i <= n; i++) {
    int count = 0;
    for(int j = 0; j <= n; j++) {
      if(G[i][j])
        count++;
    }
    if(count % 2) 
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
    while(!G[u][x] && x <= n) {
      x++;
    }
    if(x > n){
      CE.push_back(u);
      stack.pop();
    } else {
      stack.push(x);
      G[u][x] = 0;
      G[x][u] = 0;
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
    for(auto v : CE)
      cout << v << " ";
  }

  fin.close();
  return 0;
}