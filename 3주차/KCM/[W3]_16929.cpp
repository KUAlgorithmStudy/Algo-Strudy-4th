#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TwoDots {
	vector<string> board;
	vector<vector<bool>> isVisited;
	int height, width;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	stack<pair<int, int>> s;
	bool dfs(char, pair<int, int>, pair<int, int>);
public:
	TwoDots(int h = 0, int w = 0) {
		height = h;
		width = w;
		
		vector<bool> v(w, false);
		isVisited.assign(h, v);
	}
	void inputDots();
	string hasCycle();
};

void TwoDots::inputDots() {
	string s;

	for (int i = 0; i < height; i++) {
		cin >> s;
		board.push_back(s);
	}
}

string TwoDots::hasCycle() {
	bool flag = false;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (!isVisited[i][j]) {
				isVisited[i][j] = true;
				flag = flag | dfs(board[i][j], { i, j }, { -1, -1 });
			}
		}
	}

	if (flag) {
		return "Yes";
	}
	else {
		return "No";
	}
}

bool TwoDots::dfs(char color, pair<int, int> current, pair<int, int> prev) {
	int x, y;
	int flag = false;

	for (int i = 0; i < 4; i++) {
		y = current.first + dy[i];
		x = current.second + dx[i];

		if (y >= 0 && x >= 0 && y < height && x < width && board[y][x] == color) {
			if (!isVisited[y][x]) {
				isVisited[y][x] = true;
				flag = flag | dfs(color, { y, x }, current);
			}
			else {
				pair<int, int> next = { y, x };
				
				if (next != prev)
					return true;
			}
		}
	}

	return flag;
}

int main() {
	int N, M;

	cin >> N >> M;

	TwoDots td(N, M);

	td.inputDots();

	cout << td.hasCycle();
}