#include<iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
fstream fin, fout;
const int Max = 100;
int n;
vector<int> gDirected[Max];
int gUndirected[Max][Max], pOdd;
string s;
bool visited[Max];

void stringToNumber(int k) {
  s.push_back(' ');
  string tmp;
  for(auto c : s) {
    if(c == ' ') {
      int t = stoi(tmp);
      if(t) {
        gDirected[k].push_back(t);
        gUndirected[t][k] = 1;
        gUndirected[k][t] = 1;
      }
      tmp.clear();
    } else {
      tmp.push_back(c);
    }
  }
}

bool LienThongYeu() {
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

bool LienThongManh() {
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
          visited[v] = true;
          q.push(v);
        }
      }
    }
    for(int i = 1; i <= n; i++)
      if(!visited[i])
        return false;
  }
  return true;
}

string Euler() {
  int inGreaterOut = 0, outGreaterIn = 0;
  for(int i = 1; i <= n; i++) {
    int in = 0, out;
    out = gDirected[i].size();
    for(int j = 1; j <= n; j++) 
      in += count(gDirected[j].begin(), gDirected[j].end(), i);
    if(abs(in - out) > 1)
      return "No";
    if(in - out == 1)
      inGreaterOut++;
    if(out - in == 1){
      outGreaterIn++;
      pOdd = i;
    }
  }
  if(inGreaterOut == 1 && outGreaterIn == 1)
    return "semiEuler";
  if(!inGreaterOut && !outGreaterIn)
    return "Euler";
  return "No";
}

void cycleEuler(int start) {
  stack<int> stack;
  vector<int> CE;
  stack.push(start);
  while(!stack.empty()) {
    int u = stack.top();
    if(!gDirected[u].size()) {
      CE.push_back(u);
      stack.pop();
    } else {
      stack.push(gDirected[u][0]);
      gDirected[u].erase(gDirected[u].begin());
    }
  }
  for(int i = CE.size() - 1; i >= 0; i--)
    cout << CE[i] << " ";
}

int main() {
  fin.open("dske.in", ios::in);

  fin >> n;
  getline(fin, s);
  for(int i = 1; i <= n; i++) {
    getline(fin, s);
    stringToNumber(i);
  }

  if(!LienThongYeu()) {
    cout << "G khong lien thong yeu\n";
  } else {
    if(LienThongManh() && Euler() != "Euler") {
      cout << "G khong la do thi Euler\n";
    }
    if(Euler() != "semiEuler") {
      cout << "G khong lien thong manh\n";
    }
    if(Euler() == "Euler") {
      cout << "G la do thi Euler\n";
      cycleEuler(1);
    }
    if(Euler() == "semiEuler"){
      cout << "G la do thi nua Euler\n";
      cycleEuler(pOdd);
    }
  }

  fin.close();
  return 0;
}