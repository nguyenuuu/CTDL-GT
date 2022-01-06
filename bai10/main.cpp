#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<string>
#include<stack>
using namespace std;

fstream fin, fout;
const int Max = 100;
int n, tplt[100], Count = 1;
int odd;
vector<int> arr[Max];

void BFS(int u) {
  queue<int> q;
  q.push(u);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    tplt[v] = Count;
    for(auto i : arr[v]) {
      if(tplt[i] == 0) {
        q.push(i);
        tplt[i] = Count;
      }
    }
  }
}

void stringToNumber(string s, int k) {
  // s không có kí tự khoảng trắng ở cuối
  s.push_back(' ');
  string tmp;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] != ' ') 
      tmp.push_back(s[i]);
    else {
      arr[k].push_back(stoi(tmp));
      tmp.clear();
    }
  }
}

bool doThiLienThong() {
  for(int i = 1; i <= n; i++) 
    if(tplt[i] != 1)
      return false;
  return true;
}

int doThiEuler() {
  // Dồ thị Euler là đồ thị liên thông và tất cả các đỉnh có bậc chẵn
  int degreeOdd = 0;
  for(int i = 1; i <= n; i++)
    if(arr[i].size() % 2 == 1) {
      degreeOdd++;
      odd = i;
    }
  if(degreeOdd == 0) return 0; // Đồ thị Euler
  if(degreeOdd == 2) return 1; // Đồ thị nửa Euler
  return 2; // Không là đồ thị Euler cx không là nửa Euler
}

void cycleEuler(int start) {
  stack<int> stack;
  stack.push(start);
  vector<int> CE;
  while(!stack.empty()) {
    int u = stack.top();
    if(!arr[u].size()){
      CE.push_back(u);
      stack.pop();
    } else {
      stack.push(arr[u][0]);
      // Xóa cạnh arr[u][0]-u và u-arr[u][0] 
      for(int i = 0; i < arr[arr[u][0]].size(); i++) {
        if(arr[arr[u][0]][i] == u) {
          arr[arr[u][0]].erase(arr[arr[u][0]].begin() + i);
          break;
        }
      }
      arr[u].erase(arr[u].begin());
    }
  }
  for(int i = 0; i < CE.size(); i++)
    fout << CE[i] << "  ";
}

int main() {
  fin.open("dske.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);

  fin >> n;
  string s;
  // mất kí tự xuống dòng đầu tiên
  getline(fin, s);
  for(int i = 1; i <= n; i++) {
    getline(fin, s);
    stringToNumber(s, i);
  }
  BFS(1);
  if(!doThiLienThong()) {
    fout << "G khong la do thi lien thong";
  } else {
    int dtEuler = doThiEuler();
    if(dtEuler == 2) {
      fout << "G lien thong nhung khong la do thi Euler hay nua Euler";
    }
    if(dtEuler == 1) {
      fout << "G la do thi nua Euler \n";
      cycleEuler(odd);
    }
    if(dtEuler == 0) {
      fout << "G la do thi Euler \n";
      cycleEuler(1);
    }
  }

  fin.close();
  fout.close();
  return 0;
}