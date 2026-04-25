#include<iostream>
#include<vector>
using namespace std;

vector<int> parent;
int n, m;


int find (int a) {
  if (a == parent[a]) {
    return a;
  }
  return parent[a] = find (parent[a]);
}

void Union (int a, int b) {
  int pa = find(a);
  int pb = find(b);
  
  if (pb != pa)
    parent[pb] = pa;
}


int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int tmp, ttmp, tttmp;

  cin >> n >> m;
  parent.resize(n+1);
  for (int i = 0; i < n + 1; i++) {
    parent[i] = i;
  }
  for (int i = 1; i < m + 1; i++) {
    cin >> tmp >> ttmp >> tttmp;
    if (tmp == 0) {
      Union (ttmp, tttmp);
    }
    else if (tmp == 1) {
      if (find(ttmp) == find(tttmp)) {
        cout << "yes" << "\n";
      } else {
        cout << "no" << "\n";
      }
    }
  }
}
