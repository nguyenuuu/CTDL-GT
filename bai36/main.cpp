#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
using namespace std;
fstream fin;
const int Max = 100;
int n;
string s;
vector<int> G[Max], CE;

void stringToNumber(int k) {
  s.push_back(' ');
  string tmp;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == ' ') {
      G[k].push_back(stoi(tmp));
      tmp.clear();
    } else {
      tmp.push_back(s[i]);
    }
  }
}

bool Euler() {
  for(int i = 1; i <= n; i++) {
    if(G[i].size() % 2) 
      return false;
  }
  return true;
}

void cycleEuler(int start) {
  stack<int> stack;
  stack.push(start);
  while(!stack.empty()) {
    int u = stack.top();
    if(!G[u].size()) {
      CE.push_back(u);
      stack.pop();
    } else {
      int tmp = G[u][0];
      stack.push(tmp);
      // Xóa cạnh u - G[u][0]
      G[u].erase(G[u].begin());
      // Xóa cạnh G[u][0] - u
      for(int i = 0; i < G[tmp].size(); i++) {
        if(G[tmp][i] == u) {
          G[tmp].erase(G[tmp].begin() + i);
          break;
        }
      }
    }
  }
}

int main() {
  fin.open("dothi.in", ios::in);
  fin >> n;
  getline(fin, s);
  for(int i = 1; i <= n; i++) {
    getline(fin, s);
    stringToNumber(i);
  }
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