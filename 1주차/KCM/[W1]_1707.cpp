#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool bipartite_graph(int v, int e) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> vec;
	vector<vector<int>> graph(v + 1, vec); // 그래프 저장 배열

	vector<bool> set(v + 1, false); // 정점을 분리하는 배열
	vector<bool> is_visited(v + 1, false);  // BFS 방문 확인
	queue<int> q;

	bool zo = false; // BFS 한 사이클 돌 때마다 반전

	int a, b, n, size;

	for (int i = 0; i < e; i++) { // 그래프 저장
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (!is_visited[i]) {
			q.push(i);
			is_visited[i] = true;
			set[i] = !zo;
			
			size = 1;

			while (!q.empty()) {   // BFS
				for (int i = 0; i < size; i++) {
					n = q.front();
					q.pop();

					for (int j = 0; j < graph[n].size(); j++) {
						if (!is_visited[graph[n][j]]) {
							q.push(graph[n][j]);
							is_visited[graph[n][j]] = true;
							set[graph[n][j]] = zo;
						}
						else {
							if (set[graph[n][j]] != zo)
								return false;
						}
					}
				}

				zo = !zo;
				size = q.size();
			}
		}
	}

	return true;
}

int main() {
	int n, v, e;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v >> e;

		if (bipartite_graph(v, e)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}