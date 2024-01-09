#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string cmd;
	int param;
	stack<int> st;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> param;
			st.push(param);
		}
		if (cmd == "size") {
			cout << st.size() << "\n";
		}
		if (cmd == "empty") {
			cout << st.empty() << '\n';
		}
		if (cmd == "top") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << '\n';
			}
		}
		if (cmd == "pop") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
	}
	return 0;
}