#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dirX[4] = {-1, 1, 0, 0};    // 좌 우 하 상
int dirY[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, -1));
    for (int i = 0; i < N; i++) {
        /* 각 행을 string으로 입력받기 */
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';   // char를 int로 변환 (ASCII 계산 이용)
        }
    }

    /* BFS */
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dirX[dir];
            int ny = cur.second + dirY[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (map[nx][ny] != 1 || visited[nx][ny] != -1) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
        }
    }
    cout << visited[N - 1][M - 1] + 1 << '\n';

    return 0;
}