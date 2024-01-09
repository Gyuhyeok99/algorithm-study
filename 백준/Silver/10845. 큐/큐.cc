#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	int n;
	string cmd;
	int param;
	queue<int> q;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> param;
			q.push(param);
		}
		if (cmd == "size") {
			cout << q.size() << "\n";
		}
		if (cmd == "empty") {
			cout << q.empty() << "\n";
		}
		if (cmd == "front") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		if (cmd == "back") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
		if (cmd == "pop") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
	}


	return 0;
}