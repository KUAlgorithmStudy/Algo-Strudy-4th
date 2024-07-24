#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class knight {
	int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	pair<int, int> start;
	pair<int, int> dest;
	vector<vector<int>> chessboard;
	int size;
public:
	knight() {
		start = { 0, 0 };
		dest = { 0, 0 };
		size = 0;
	}
	void input();
	int numOfMove();
};

void knight::input() {
	int n, x, y;

	cin >> n;

	this->size = n;

	vector<int> v(n, -1);
	chessboard.assign(n, v);

	cin >> x >> y;
	start.first = x;
	start.second = y;

	cin >> x >> y;
	dest.first = x;
	dest.second = y;
}

int knight::numOfMove() {
	if (start == dest)
		return 0;

	queue<pair<int, int>> q;
	int move = 0;
	int qn;
	pair<int, int> current;
	int x, y;

	q.push(start);
	chessboard[start.second][start.first] = 0;

	while (!q.empty()) {
		qn = q.size();
		move++;

		for (int i = 0; i < qn; i++) {
			current = q.front();
			q.pop();

			for (int j = 0; j < 8; j++) {
				x = current.first + dx[j];
				y = current.second + dy[j];

				if (x >= 0 && y >= 0 && x < size && y < size && chessboard[y][x] == -1) {
					if (x == dest.first && y == dest.second)
						return move;

					chessboard[y][x] = move;
					q.push({ x, y });
				}
			}
		}
	}
}

int main() {
	int testcase;
	knight k;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		k.input();
		cout << k.numOfMove() << "\n";
	}
}