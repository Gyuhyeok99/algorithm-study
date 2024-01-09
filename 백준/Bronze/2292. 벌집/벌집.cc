#include <iostream>

using namespace std;

int main() {

	long n;
	int moveleast = 1;
	cin >> n;
	int v = 1;
	for (int i = 1; ; i++) {
		if (n == 1) {
			break;
		}
		v += 6 * i;
		moveleast++;
		if (v >= n) {
			break;
		}
	}
	cout << moveleast;
	return 0;
}