#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<stack>
using namespace std;
fstream fin, fout;
int n;
string s;

void removeSpace() {
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == ' ') {
      s.erase(s.begin() + i);
      i--;
    }
  }
}


string solve() {
  string res;
  stack<char> stack;
  for(auto c : s) {
    // nếu là dấu mở ngoặc
    if(c == '(') {
      stack.push(c);
      continue;
    }
    // Nếu là toán tử
    if(c == '-' || c== '+' || c == '/' || c == '*') {
      // nếu stack rỗng
      if(stack.empty()) {
        stack.push(c);
        continue;
      }
      // Nếu độ ưu tiên của c lớn hơn hoặc bằng phần tử đầu của stack
      if(((c == '*' || c == '/') && (stack.top() == '+' || stack.top() == '-')) || c == stack.top() || stack.top() == '(') {
        stack.push(c);
        continue;
      }
      // Nếu độ ưu tiên của c nhỏ hơn phần tử đầu của stack
      res.push_back(stack.top());
      stack.pop();
      continue;
    }
    // Nếu là dấu đóng ngoặc
    if(c == ')') {
      while(stack.top() != '(') {
        res.push_back(stack.top());
        stack.pop();
      }
      stack.pop();
      continue;
    }
    // Nếu là toán hạng
    res.push_back(c);
  }
  while(!stack.empty()) {
    res.push_back(stack.top());
    stack.pop();
  }
  return res;
}

int main() {
  fin.open("trungto.in", ios::in);
  fout.open("hauto.out", ios::out | ios::trunc);
  fin >> n;
  fout << n << "\n";
  // mất kí tự xuống dòng đầu tiên
  getline(fin, s);
  while(n--) {
    getline(fin, s);
    removeSpace();
    fout << solve() << "\n";
  }
 
  
  fin.close();
  fout.close();
  return 0;
}