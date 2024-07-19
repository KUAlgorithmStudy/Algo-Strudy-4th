#include <iostream>
#include <vector>
using namespace std;

class NumberOfIsland {
	int height;
	int width;
	vector<vector<int>> map;
	void dfs(pair<int, int>);
	int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
public:
	NumberOfIsland() {
		height = 0;
		width = 0;
	}
	bool input();
	int countIsland();
};

bool NumberOfIsland::input() {
	cin >> width >> height;

	if (width == 0 && height == 0)
		return false;

	vector<int> v(width, 0);
	map.assign(height, v);

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			cin >> map[i][j];

	return true;
}

void NumberOfIsland::dfs(pair<int, int> crd) {
	map[crd.second][crd.first] = 0;

	int x, y;

	for (int i = 0; i < 8; i++) {
		x = crd.first + dx[i];
		y = crd.second + dy[i];

		if (x >= 0 && y >= 0 && x < width && y < height && map[y][x] == 1)
			dfs({ x, y });
	}
}

int NumberOfIsland::countIsland() {
	int count = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j] == 1) {
				count++;
				dfs({ j, i });
			}
		}
	}

	return count;
}

int main() {
	NumberOfIsland ni;

	while (ni.input()) {
		cout << ni.countIsland() << "\n";
	}
}