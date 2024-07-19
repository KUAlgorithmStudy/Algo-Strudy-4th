#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SubwayLineTwo {
	vector<vector<int>> subway;
	vector<bool> isVisited;
	vector<int> distance;
	vector<int> circleLine;
	int N;
	bool dfs(int, int);
public:
	SubwayLineTwo(int n = 3) {
		this->N = n;

		vector<int> v;
		subway.assign(n + 1, v);

		isVisited.assign(n + 1, false);
		distance.assign(n + 1, -1);
	}
	void sectionInput();
	void findCircleLine();
	void calculateDistance();
	void printDistance();
};

void SubwayLineTwo::sectionInput() {
	int a, b;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		subway[a].push_back(b);
		subway[b].push_back(a);
	}
}

void SubwayLineTwo::findCircleLine() {
	dfs(1, 0);
	int n = 0;
	
	for (int i = 0; i < circleLine.size(); i++) {
		if (circleLine[i] == circleLine[circleLine.size() - 1]) {
			n = i;
			break;
		}
	}

	circleLine.erase(circleLine.begin(), circleLine.begin() + n);
}

bool SubwayLineTwo::dfs(int n, int prev) {
	isVisited[n] = true;
	circleLine.push_back(n);

	for (int i = 0; i < subway[n].size(); i++) {
		if (!isVisited[subway[n][i]]) {
			if (dfs(subway[n][i], n)) {
				return true;
			}
		}
		else if (subway[n][i] != prev) {
			circleLine.push_back(subway[n][i]);
			return true;
		}
	}

	circleLine.pop_back();
	return false;
}

void SubwayLineTwo::calculateDistance() {
	for (int i : circleLine)
		distance[i] = 0;

	queue<int> q;
	int qIt, qn;
	int d;

	for (int i : circleLine) {
		for (int j : subway[i]) {
			if (distance[j] == -1) {
				q.push(j);
			}
		}

		d = 0;
		while (!q.empty()) {
			qIt = q.size();
			d++;

			for (int j = 0; j < qIt; j++) {
				qn = q.front();
				q.pop();

				distance[qn] = d;

				for (int k = 0; k < subway[qn].size(); k++)
					if (distance[subway[qn][k]] == -1)
						q.push(subway[qn][k]);
			}
		}
	}
}

void SubwayLineTwo::printDistance() {
	for (int i = 1; i <= N; i++)
		cout << distance[i] << ' ';
}

int main() {
	int N;

	cin >> N;

	SubwayLineTwo slt(N);

	slt.sectionInput();
	slt.findCircleLine();
	slt.calculateDistance();
	slt.printDistance();
}