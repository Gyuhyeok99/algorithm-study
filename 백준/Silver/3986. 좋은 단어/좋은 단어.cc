#include <iostream>
#include <stack>
using namespace std;

int n, cnt;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        stack<char> st;
        for(int j = 0; j < s.size(); j++) {
            if(st.empty() || st.top() != s[j]) {
                st.push(s[j]);
            } else {
                st.pop();
            }
        }
        if(st.empty()) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}