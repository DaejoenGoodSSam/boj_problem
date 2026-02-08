#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int height[501][501];
int M,N;
int result = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs (int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx < M + 1 && ny < N + 1 && height[x][y] > height[nx][ny]) {
            if (nx == M && ny == N) {
                result++;
            }
            else {
                dfs(nx , ny);
            }
        }
    }
}


int main () {ios_base::sync_with_stdio(0); cin.tie(0);
    int M,N;
    cin >> M >> N;
    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cin >> height[i][j];
        }
    }
    dfs(1,1);
    cout << result;
}