#include <iostream>
#include <stack>
using namespace std;

int n, ret;
string s;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> s;
    st.push(-1);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                ret = max(ret, i - st.top());
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
