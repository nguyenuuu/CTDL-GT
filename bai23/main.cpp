/*
1.  Sắp xếp các cạnh của đồ thị G theo thứ tự tăng dần của trọng số cạnh;
2.  Xuất phát từ tập cạnh T=φ, ở mỗi bước, ta sẽ lần lượt duyệt trong danh sách các cạnh đã được sắp xếp, từ cạnh có trọng số nhỏ đến cạnh có trọng số lớn để tìm ra cạnh mà khi bổ sung nó vào T không tạo thành chu trình trong tập các cạnh đã được bổ sung vào T trước đó;
3.  Thuật toán sẽ kết thúc khi ta thu được tập T gồm n-1 cạnh.
*/

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
fstream fin, fout;
const int Max = 100;
struct EDGE {
  int u, v, w;
};
EDGE edge[Max];
vector<EDGE> res;
int n, m, parent[Max];

bool cmp(EDGE a, EDGE b) {
  return a.w < b.w;
}

int findParent(int u) {
  // Khi chưa có đỉnh cha thì gắn chính nó là cha
  if(!parent[u]) return u;
  return parent[u];
}

void Kruskal() {
  for(int i = 0; i < m; i++) {
    int p_u = findParent(edge[i].u);
    int p_v = findParent(edge[i].v);
    // Nếu khác cha có nghĩa là k tạo thành 1 chu trình
    if(p_u != p_v) {
      res.push_back(edge[i]);
      // Cập nhật cha của 2 đỉnh của cạnh đang xét
      parent[edge[i].u] = p_u;
      parent[edge[i].v] = p_v;
      // Cập nhập những đỉnh có cha là p_v thành p_u
      for(int j = 1; j <= n; j++) {
        if(parent[j] == p_v)
          parent[j] = p_u;
      }
    }
  }
}

int main() {
  fin.open("dothi.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);
  fin >> n >> m;
  for(int i = 0; i < m; i++) {
    fin >> edge[i].u >> edge[i].v >> edge[i].w;
  }

  sort(edge, edge + m, cmp);
  Kruskal();
  int Min = 0;
  for(auto e : res) Min += e.w;
  fout << Min << "\n";
  for(auto e : res)
    fout << e.u << " " << e.v << "\n";

  fin.close();
  fout.close();
  return 0;
}