#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int count = 1;

void bfs(const vector<int> graph[], vector<int>& visited, int start_node) {
    // if (visited[start_node] != 0)
	// 	return;

	visited[start_node] = ::count++;

	queue<int> q;
	q.push(start_node);
    while (!q.empty()) {
		int curr_node = q.front();
		q.pop();

		for (auto& next : graph[curr_node]) {
            if (visited[next] != 0)
				continue;

			visited[next] = ::count++;
			q.push(next);
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;

	vector<int> graph[n + 1];
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

    for (int i = 1; i <= n; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}

	vector<int> visited(n + 1, 0);

	bfs(graph, visited, r);

	for (int i = 1; i <= n; ++i)
		cout << visited[i] << '\n';
}