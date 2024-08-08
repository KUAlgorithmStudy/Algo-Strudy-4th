#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sensor {
	int numOfSen;		//센서의 개수
	int numOfCon;		//집중국의 개수
	vector<int> sen;
	vector<int> distance;
public:
	Sensor(int n = 0, int k = 0) {
		numOfSen = n;
		numOfCon = k;
		sen.assign(n, 0);
	}
	void inputSen();
	int findMin();
};

void Sensor::inputSen() {
	for (int i = 0; i < numOfSen; i++)
		cin >> sen[i];

	sort(sen.begin(), sen.end());
	sen.erase(unique(sen.begin(), sen.end()), sen.end());

	numOfSen = sen.size();
}

int Sensor::findMin() {
	if (numOfSen <= numOfCon)
		return 0;

	for (int i = 0; i < numOfSen - 1; i++)
		distance.push_back(sen[i + 1] - sen[i]);
	sort(distance.begin(), distance.end());

	int sum = 0;
	for (int i = 0; i < distance.size() - numOfCon + 1; i++)
		sum += distance[i];
	
	return sum;
}

int main() {
	int N, K;

	cin >> N;
	cin >> K;

	Sensor sen(N, K);
	sen.inputSen();

	cout << sen.findMin();
}