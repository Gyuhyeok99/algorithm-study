#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	int r;
	string s;
	for (int i = 0; i < t; i++) {
		cin >> r >> s;
		int len = s.length();
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < r; k++) {
				cout << s[j];
			}
		}
		cout << '\n';
	}
	return 0;
}