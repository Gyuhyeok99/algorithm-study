#include <iostream>
#include <stack>
using namespace std;

int main() {

    string parenthesis;
    int n;
    bool flag;
    cin >> n;
    for(int i = 0; i < n; i++) {
        stack<char> stack;
        cin >> parenthesis;
        flag = true;
        for(int j = 0; j < parenthesis.size(); j++) {
            if(parenthesis[j] == '(') {
                stack.push(parenthesis[j]);
            }
            else if(parenthesis[j] == ')') {
                if(stack.empty()) {
                    flag = false;
                    break;
                }
                stack.pop();
            }
        }
        if(!(stack.empty())){
            flag = false;
        }

        if(flag) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
