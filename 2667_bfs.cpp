#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 26
using namespace std;
int N,tmp = 0;
    string arr[MAX];
    bool visited[MAX][MAX] = {0, };
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<int> result;
    queue<pair<int,int>> q;
    void bfs(int x,int y) {
        q.push({x,y});
        visited[x][y] = true;
        tmp++;

        while(!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = a + dx[i];
                int ny = b + dy[i];
                if (0 <= nx && 0<= ny && nx < N && ny < N && visited[nx][ny] == false && arr[nx][ny] == '1' ) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    tmp++;
                }
            }
        }
    }

int main() {ios_base :: sync_with_stdio(0);
        cin >> N;
     for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == '1' && visited[i][j] == false) {
                    bfs(i,j);
                    result.push_back(tmp);
                    tmp = 0;
                }
            }
        }
        sort(result.begin(), result.end());
        cout << result.size() << endl;
        for (int i = 0 ; result.size(); i++) {
            cout << result[i] << "\n";
        }
}