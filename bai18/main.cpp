#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
using namespace std;
fstream fin, fout;
int n;
string s;

vector<string> stringToList() {
  s.push_back(' ');
  vector<string> res;
  string tmp;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] != ' ') 
      tmp.push_back(s[i]);
    else {
      res.push_back(tmp);
      tmp.clear();
    }
  }
  return res;
}

int calc(vector<string> v) {
  stack<string> res;
  for(auto u : v) {
    // Nếu gặp toán tử thì tính 2 số hạng đầu tiên của stack
    if(u == "+" || u == "-" || u == "*" || u == "/") {
      int a = stoi(res.top());
      res.pop();
      int b = stoi(res.top());
      res.pop();
      if(u == "+") res.push(to_string(b + a));
      if(u == "-") res.push(to_string(b - a));
      if(u == "*") res.push(to_string(b * a));
      if(u == "/") res.push(to_string(b / a));
      continue;
    }
    // thêm toán hạng vào stack
    res.push(u);
  }
  return stoi(res.top());
}

int main() {
  fin.open("hauto.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);

  fin >> n;
  fout << n << "\n";
  // mất kí tự xuống dòng đầu tiên
  getline(fin, s);
  while(n--) {
    getline(fin, s);
    vector<string> list = stringToList();
    fout << calc(list) << "\n";
  }
  
  fin.close();
  fout.close();
  return 0;
}