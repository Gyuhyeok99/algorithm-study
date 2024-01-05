#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int total = 0;
	char ch;
	for (int i = 0; i < N; i++) {
		cin >> ch;
		total += ch - 48;
	}
	cout << total;
	return 0;
}