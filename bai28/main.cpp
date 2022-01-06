#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n;
string s;
vector<int> gDirected[Max];
int gUndirected[Max][Max];
bool visited[Max];

void stringToNumber(int k) {
  s.push_back(' ');
  string tmp;
  for(auto c : s) {
    if(c == ' ') {
      int t = stoi(tmp);
      if(t) {
        gDirected[k].push_back(t);
        gUndirected[k][t] = 1;
        gUndirected[t][k] = 1;
      }
      tmp.clear();
    } else {
      tmp.push_back(c);
    }
  }
}

bool lienThongYeu() {
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int u = q.front();
    visited[u] = true;
    q.pop();
    for(int i = 1; i <= n; i++) {
      if(!visited[i] && gUndirected[u][i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
  for(int i = 1; i <= n; i++) 
    if(!visited[i])
      return false;
  return true;
}

bool lienThongManh() {
  for(int i = 1; i <= n; i++) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
      int u = q.front();
      visited[u] = true;
      q.pop();
      for(auto v : gDirected[u]) {
        if(!visited[v]) {
          q.push(v);
          visited[v] = true;
        }
      }
    }
    for(int j = 1; j <= n; j++)
      if(!visited[j])
        return false;
  }
  return true;
}

int main() {
  fin.open("dske.in", ios::in);

  fin >> n;
  getline(fin, s);
  for(int i = 1; i <= n; i++) {
    getline(fin, s);
    stringToNumber(i);
  }

  if(!lienThongYeu()) {
    cout << "Do thi khong lien thong manh, khong lien thong yeu\n";
  } else {
    if(lienThongManh()) 
      cout << "Do thi lien thong manh\n";
    else cout << "Do thi lien thong yeu\n";
  }

  fin.close();
  return 0;
}