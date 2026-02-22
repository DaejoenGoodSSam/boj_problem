<<<<<<< Updated upstream
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
=======
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

>>>>>>> Stashed changes
using namespace std;
int height[501][501];
int visited[501][501];
int M,N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs (int x, int y) {
<<<<<<< Updated upstream
    if (visited[x][y] != -1) {
=======
    if (x == M && y == N) {
        return 1;
    }
    cout << "[dfs] x : " << x << " y : " << y  << " height : " << height[x][y] << endl;
    if (visited[x][y] != -1)  {
>>>>>>> Stashed changes
        return visited[x][y];
    }
    int result = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
<<<<<<< Updated upstream
        if (height[x][y] > height[nx][ny] && nx > 0 && ny > 0 && nx < M + 1 && ny < N + 1) {
            if (nx == M && ny == N) {
                return 1;
            }
            else {
                visited[nx][ny] = dfs(nx, ny);
                result = result + visited[nx][ny];
            }
        }
    }
=======
        cout << "  --> nx : " << nx << " ny : " << ny  << " M : " << M << " N : " << N;
        cout << " height[nx][ny] : " << height[nx][ny]  << endl;
        if (nx > 0 && ny > 0 && nx < M + 1 && ny < N + 1 ) {
            if (height[x][y] > height[nx][ny]) {
                result = result + dfs(nx, ny);
            }
        }
    }

>>>>>>> Stashed changes
    return result;
}


int main () {ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    memset(visited, -1, sizeof(visited));
    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cin >> height[i][j];
        }
    }
<<<<<<< Updated upstream
    memset(visited, -1 , sizeof(visited));
=======

>>>>>>> Stashed changes
    cout << dfs(1,1);
}