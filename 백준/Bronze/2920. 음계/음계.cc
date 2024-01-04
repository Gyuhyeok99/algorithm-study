#include <iostream>
using namespace std;

int main() {
	int x[8];
	int a = 0;
	int b = 0;
	for (int i = 0; i < 8; i++) {
		cin >> x[i];
	}
	int y = x[0];
	for (int i = 1; i < 8; i++) {
		if ((x[i] - y) == 1) {
			a++;
		}
		if ((x[i] - y) == -1) {
			b++;
		}
		y = x[i];
	}
	string ans1 = "ascending";
	string ans2 = "descending";
	string ans3 = "mixed";
	if (a == 7) {
		cout << ans1;
	}
	else if (b == 7) {
		cout << ans2;
	}
	else cout << ans3;
}