#include <iostream>
#include <vector>
using namespace std;

class inequal {
	string minN, maxN;
	int numOfSign;
	vector<char> sign;
	vector<int> numbers;
	vector<bool> isSelected;
	string numString;
public:
	inequal(int n = 0) {
		numOfSign = n;
		sign.assign(n, ' ');

		minN.assign(n + 1, '9');
		maxN.assign(n + 1, '0');
		isSelected.assign(10, false);
	}
	void inputSign();
	void findnum(int);
	void print();
};

void inequal::inputSign() {
	for (int i = 0; i < numOfSign; i++)
		cin >> sign[i];
}

void inequal::findnum(int notSelected) {
	if (notSelected == 0) {
		numString = "";
		for (int i = 0; i < numbers.size(); i++)
			numString += (numbers[i] + '0');

		if (maxN < numString)
			maxN = numString;
		if (minN > numString)
			minN = numString;

		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!isSelected[i]) {
			if (!numbers.empty()) {
				if (sign[numbers.size() - 1] == '>' && numbers[numbers.size() - 1] < i)
					continue;
				if (sign[numbers.size() - 1] == '<' && numbers[numbers.size() - 1] > i)
					continue;
			}

			isSelected[i] = true;
			numbers.push_back(i);
			
			findnum(notSelected - 1);

			isSelected[i] = false;
			numbers.pop_back();
		}
	}
}

void inequal::print() {
	cout << maxN << "\n" << minN;
}

int main() {
	int k;

	cin >> k;

	inequal iq(k);
	iq.inputSign();
	
	iq.findnum(k + 1);

	iq.print();
}