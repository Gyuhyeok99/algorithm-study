#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string cmd;
	int param;
	deque<int> dq;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> param;
			dq.push_front(param);
		}
		if (cmd == "push_back") {
			cin >> param;;
			dq.push_back(param);
		}
		if (cmd == "size") {
			cout << dq.size() << "\n";
		}
		if (cmd == "empty") {
			cout << dq.empty() << "\n";
		}
		if (cmd == "front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
			}
		}
		if (cmd == "back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << "\n";
			}
		}
		if (cmd == "pop_front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		if (cmd == "pop_back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
	}
	return 0;
}