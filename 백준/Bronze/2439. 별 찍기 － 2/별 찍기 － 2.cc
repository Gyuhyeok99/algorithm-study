#include <iostream>

using namespace std;


int main() {
	short N;

	string space = " ";
	cin >> N;
	int k = 1;
	for (int i = 1; i <= N; i++) {
		for (k; k < N; k++)
			cout << space;
		k = i + 1;
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << '\n';
	}
}