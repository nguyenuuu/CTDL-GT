#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<typeinfo>
using namespace std;
fstream fin, fout;
int nNode;
struct node {
  string str;
  int count;
  node *left;
  node *right;
};

void display(node *tree) {
  if(tree != NULL) {
    fout << tree->str << " " << tree->count << "\n";
    display(tree->left);
    display(tree->right);
  }
}

void numberNode(node *tree) {
  if(tree != NULL) {
    nNode++;
    numberNode(tree->left);
    numberNode(tree->right);
  }
}

node* insert(node *tree, string s) {
  if(tree == NULL) {
    node *tmp = new node;
    tmp->str = s;
    tmp->count = 1;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
  }
  // s is smaller than tree->str
  if(s.compare(tree->str) < 0)
    tree->left = insert(tree->left, s);
  else {
    // s is longer than tree->str
    if(s.compare(tree->str) > 0)
      tree->right = insert(tree->right, s);
    // s is equal to tree->str
    else tree->count++;
  }
  return tree;
}

int main() {
  fin.open("data.in", ios::in);
  fout.open("ketqua.out", ios::out | ios::trunc);

  string s;
  node *tree = NULL;
  while(!fin.eof()) {
    fin >> s;
    tree = insert(tree, s);
  }
  numberNode(tree);
  fout << nNode << "\n";
  display(tree);

  fin.close();
  fout.close();
  return 0;
}