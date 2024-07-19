#include <iostream>
using namespace std;

int calHeight(string plate) {
	int sum = 10;
	char shape = plate[0];

	for (int i = 1; i < plate.length(); i++) {
		if (plate[i] == shape) {
			sum += 5;
		}
		else {
			shape = plate[i];
			sum += 10;
		}
	}

	return sum;
}

int main() {
	string s;

	cin >> s;

	cout << calHeight(s);
}