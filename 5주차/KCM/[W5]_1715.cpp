#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N;
	int numOfComp = 0;
	vector<int> numOfCard;
	queue<int> q;

	cin >> N;
	numOfCard.assign(N, 0);

	for (int i = 0; i < N; i++)
		cin >> numOfCard[i];

	if (N == 1) {
		cout << 0;
		return 0;
	}

	sort(numOfCard.begin(), numOfCard.end());

	numOfComp += numOfCard[0] + numOfCard[1];
	q.push(numOfCard[0] + numOfCard[1]);

	int it = 2;
	int n1, n2, comp;

	while (it < N || q.size() > 1) {
		comp = q.front();
		
		if (it < N && numOfCard[it] < comp) {
			n1 = numOfCard[it++];
		}
		else {
			n1 = comp;
			q.pop();
		}

		if (!q.empty()) {
			comp = q.front();
		}
		else {
			comp = 1001;
		}

		if (it < N && numOfCard[it] < comp) {
			n2 = numOfCard[it++];
		}
		else {
			n2 = comp;
			q.pop();
		}

		numOfComp += n1 + n2;
		q.push(n1 + n2);
	}

	cout << numOfComp;
}