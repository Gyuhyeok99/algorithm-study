#include <iostream>
#include <stack>
using namespace std;

int n;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        stack<char> st;
        bool flag = true;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '(') {
                st.push(s[j]);
            }
            else if(st.empty() && s[j] == ')') {
                flag = false;
            }
            else if(st.size() && s[j] == ')' && st.top() == '(') {
                st.pop();
            }
        }
        if(st.empty() && flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}