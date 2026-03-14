#include<iostream>
#include<vector>
using namespace std;

vector<int>parent;
int n, m;


void Union (int a, int b) {
  int pa = parent[a];
  int pb = parent[b];
  
  if (pa < pb)
    parent[pb] = pa;
  else
    parent[pa] = pb;
}

int find (int a) {
  if (a == parent[a]) {
    return a;
  }
  return parent[a] = find (parent[a]);
}

int main() {
  int tmp, ttmp, tttmp;
  cin >> n >> m;
  for (int i = 0; i < n + 1; i++) {
    parent.push_back(i);
  }
  for (int i = 1; i < m + 1; i++) {
    cin >> tmp >> ttmp >> tttmp;
    if (tmp == 0) {
      Union (ttmp, tttmp);
    }
    else if (tmp == 1) {
      if (find(ttmp) == find(tttmp)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
}
