#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(const vector<vector<int>> adl, vector<int>& visit, int current) {
    if (visit[current - 1] != 0) {
        return;
    }
    visit[current - 1] = 1;
    for (auto next : adl[current - 1]) {
        if (visit[next - 1] == 0) {
            dfs(adl, visit, next);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int M;
    cin >> N >> M;
    vector <vector<int>> adl (N);
    vector <int> visit (N,0);
    for (int i = 0; i < M; i++) {
        int tmp;
        int ttmp;
        cin >> tmp >> ttmp;
        adl[ttmp - 1].push_back(tmp);
        adl[tmp - 1].push_back(ttmp);
    }
    dfs(adl, visit, 1);
    int tttmp = 0;
    for (int i = 1; i < N; i++) {
        if (visit[i] == 1) {
            tttmp++;
        }
    }
    cout << tttmp;
}