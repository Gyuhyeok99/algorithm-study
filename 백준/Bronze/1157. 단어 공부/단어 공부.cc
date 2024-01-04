#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char x[1000005];
	int alp[26];
	int max = 0;
	char ans;

	for (int i = 0; i < sizeof(alp) / sizeof(int); i++) {
		alp[i] = 0;
	}
	cin >> x;
	int len = strlen(x);
	for (int i = 0; i < len; i++) {
		if (x[i] >= 'a') {
			alp[x[i] - 'a']++;
		}
		else alp[x[i] - 'A'] ++;
	}

	for (int i = 0; i < sizeof(alp) / sizeof(int); i++) {
		if (alp[i] == max) {
			ans = '?';
		}
		
		else if (alp[i] > max) {
			max = alp[i];
			ans = 'A' + i;
		}
	}
	cout << ans;
	return 0;
}