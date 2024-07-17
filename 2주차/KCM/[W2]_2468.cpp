#include <iostream>
#include <vector>
using namespace std;

class SafeArea {
	vector<vector<int>> height;
	vector<vector<bool>> isVisited;
	int N;
	int wh;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	void dfs(pair<int, int>);
	int countSafeArea();
public:
	SafeArea(int N = 1) {
		this->N = N;
		wh = 0;

		vector<int> v(N, 0);
		height.assign(N, v);

		vector<bool> v2(N, false);
		isVisited.assign(N, v2);
	}
	void heightInput();
	int maxSafeArea();
};

void SafeArea::heightInput() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> height[i][j];
}

void SafeArea::dfs(pair<int, int> crd) {
	isVisited[crd.second][crd.first] = true;

	int x, y;

	for (int i = 0; i < 4; i++) {
		x = crd.first + dx[i];
		y = crd.second + dy[i];

		if (x >= 0 && y >= 0 && x < N && y < N && !isVisited[y][x] && height[y][x] > wh)
			dfs({ x, y });
	}
}

int SafeArea::countSafeArea() {  // wh = Water Height
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!isVisited[i][j] && height[i][j] > wh) {
				count++;
				dfs({ j, i });
			}
		}
	}

	vector<bool> v(N, 0);
	isVisited.assign(N, v);

	return count;
}

int SafeArea::maxSafeArea() {
	vector<int> v(N, 0);
	int max = 0;
	int countArea;
	
	for (wh = 0; wh < 101; wh++) {
		countArea = countSafeArea();

		if (max < countArea)
			max = countArea;

		if (countArea == 0)
			break;
	}

	return max;
}

int main() {
	int n;

	cin >> n;

	SafeArea sa(n);

	sa.heightInput();
	
	cout << sa.maxSafeArea();
}