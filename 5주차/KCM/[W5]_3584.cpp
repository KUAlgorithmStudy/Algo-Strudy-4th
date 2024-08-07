#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	int N;
	int parents, child;
	unordered_map <int, int> tree;
	unordered_set <int> ancestor;
	int node1, node2;
	int current;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		for (int j = 0; j < N - 1; j++) {
			cin >> parents >> child;
			tree[child] = parents;
		}

		cin >> node1 >> node2;
		ancestor.insert(node1);

		current = node1;
		while (tree.find(current) != tree.end()) {
			ancestor.insert(tree[current]);
			current = tree[current];
		}

		current = node2;
		while (ancestor.find(current) == ancestor.end())
			current = tree[current];

		cout << current << "\n";

		ancestor.clear();
		tree.clear();
	}
}