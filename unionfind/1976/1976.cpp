#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[201][201];
int city[201];
int n,m;

int order[1001];


int find (int a) {
  if (city[a] == a) 
    return a;
  return city[a] = find(city[a]);

}

void Union(int a, int b) {
  int pa = find(a);
  int pb = find(b);
  if (pa != pb) {
    city[pb] = pa;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 0; i < n ; i++ ) {
    city[i] = i;
  }


  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      int tmp;
      cin >> tmp;
      if (tmp == 1) {
        Union(i,j);
        map[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> order[i];
  }

  for (int i = 0; i < m-1; i++) {
    if (order[i] != order[i + 1] && find(order[i]) != find(order[i+1])) {
      cout << "NO";
      break;
    }
    if (i == m - 2) {
      cout << "YES";
    }
  }
}
