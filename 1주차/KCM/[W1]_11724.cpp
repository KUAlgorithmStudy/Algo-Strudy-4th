#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connected_component(int vertex, int edge) {
	vector<vector<int>> graph(vertex + 1);
	vector<bool> is_visited(vertex + 1, false);
	int a, b, size, n;
	queue<int> q;
	int cnt = 0;

	for (int i = 0; i < edge; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= vertex; i++) {
		if (is_visited[i])
			continue;

		cnt++;

		q.push(i);
		size = 1;

		while (!q.empty()) {
			for (int j = 0; j < size; j++) {
				n = q.front();
				q.pop();

				for (int k = 0; k < graph[n].size(); k++) {
					if (!is_visited[graph[n][k]]) {
						q.push(graph[n][k]);
						is_visited[graph[n][k]] = true;
					}
				}
			}

			size = q.size();
		}
	}

	return cnt;
}

int main() {
	int v, e;

	cin >> v >> e;

	cout << connected_component(v, e);
}