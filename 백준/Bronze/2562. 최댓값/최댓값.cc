#include <iostream>
using namespace std;

int main() {
	int arr[9];
	int max = 0;
	int x;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i];
			x = i + 1;
		}
	}
	cout << max << endl;
	cout << x << endl;
	return 0;
}