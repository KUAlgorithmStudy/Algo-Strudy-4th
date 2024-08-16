#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> A, B, C;
	int lenA, lenB;

	cin >> lenA >> lenB;
	A.assign(lenA, 0);
	B.assign(lenB, 0);

	for (int i = 0; i < lenA; i++)
		cin >> A[i];
	for (int i = 0; i < lenB; i++)
		cin >> B[i];

	C.resize(A.size() + B.size());
	merge(A.begin(), A.end(), B.begin(), B.end(), C.begin());

	for (int i = 0; i < C.size(); i++)
		cout << C[i] << ' ';
}


/*
int main() {
	vector<int> A;
	vector<int> B;
	vector<int> C;
	int lenA, lenB, lenC;
	int itA = 0, itB = 0, itC = 0;
	int compA, compB;

	cin >> lenA >> lenB;
	A.assign(lenA, 0);
	B.assign(lenB, 0);
	C.assign(lenA + lenB, 0);
	lenC = lenA + lenB;
	
	for (int i = 0; i < lenA; i++)
		cin >> A[i];
	for (int i = 0; i < lenB; i++)
		cin >> B[i];

	while (itA < lenA || itB < lenB) {
		if (itA < lenA) {
			compA = A[itA];
		}
		else {
			while (itB < lenB)
				C[itC++] = B[itB++];
			break;
		}

		if (itB < lenB) {
			compB = B[itB];
		}
		else {
			while (itA < lenA)
				C[itC++] = A[itA++];
			break;
		}

		if (compA < compB) {
			C[itC++] = compA;
			itA++;
		}
		else {
			C[itC++] = compB;
			itB++;
		}
	}

	for (int i = 0; i < lenC; i++) {
		cout << C[i] << ' ';
	}
}
*/