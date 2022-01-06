#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<map>
using namespace std;
fstream fin, fout;
map<string, int> word;

int main() {
  fin.open("data.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  string s;
  while(!fin.eof()) {
    fin >> s;
    word[s]++;
  }

  fout << word.size() << "\n";
  for(auto itr = word.begin(); itr != word.end(); itr++) {
    fout << itr->first << " " << itr->second << "\n";
  }
  
  fin.close();
  fout.close();
  return 0;
}