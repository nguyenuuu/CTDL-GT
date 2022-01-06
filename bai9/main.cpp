/*
  Tìm đường đi của từng đỉnh đến các đỉnh còn lại bằng dfs
  => tổng hợp tất cả các cạnh vào map => in kết quả
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
fstream fin, fout;
const int Max = 100;
int G[Max][Max], n, parent[Max]; // lưu đường đi từ đỉnh cha đến đỉnh con: parent[i] -> i
bool visited[Max];
vector<pair<int, int>> res;

void DFS(int u) {
  visited[u] = true; 
  for(int i = 1; i <= n; i++) {
    if(!visited[i] && G[u][i]) {
      parent[i] = u;
      DFS(i);
    }
  }
}

int main() {
  fin.open("data.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);

  fin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      fin >> G[i][j];

  int ok = 1;
  for(int i = 1; i <= n; i++) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    // Duyệt đường đi từng đỉnh 
    DFS(i);
    int count = 0; // biến đếm số đỉnh có parent = 0; Nếu >= 2 thì nó không liên thông => Bài vô nghiệm
    for(int j = 1; j <= n; j++) {
      if(!parent[j]) 
        count++;
      else {
        // Thêm tất cả các cạnh parent[j]->j vào kết quả
        res.push_back({parent[j], j});
      }
    }
    if(count > 1) {
      ok = 0;
      break;
    }
  }

  
  if(!ok) {
    fout << "Vo nghiem";
  } else {
    sort(res.begin(), res.end());
    res.erase( unique( res.begin(), res.end() ), res.end() );
    for(auto v : res) 
      cout << v.first << " " << v.second << "\n";  
  }

  fin.close();
  fout.close();
  return 0;
}