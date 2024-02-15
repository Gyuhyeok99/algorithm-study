#include <iostream>
#include <stack>
using namespace std;

string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    while(true) {
        getline(cin, s);
        bool flag = true;
        if (s[0] == '.' && s.size() == 1) return 0;
        stack<char> st;
        for(int i = 0; s[i] != '.';i++) {
            if(s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']') {
                if(st.empty() || s[i] == ')' && st.top() != '(' || s[i] == ']' && st.top() != '[') {
                    flag = false;
                    break;
                }
                st.pop();
            }
        }
        if(st.empty() && flag) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}