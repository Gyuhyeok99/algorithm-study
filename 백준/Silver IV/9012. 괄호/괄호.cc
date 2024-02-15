#include <iostream>
#include <stack>

using namespace std;
int n;
string s;
bool flag;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        stack<char> stack;
        flag = true;
        for(int j = 0; j < s.size(); j++) {
            if(stack.size() == 0 && s[j] == ')') {
                flag = false;
                break;
            }
            if(s[j] == '(') {
                stack.push('(');
            }
            else {
                if(stack.size() && stack.top() == '(') {
                    stack.pop();
                }
            }
        }
        if(stack.empty() && flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
