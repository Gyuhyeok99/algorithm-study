#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

    string parenthesis;
    bool flag;
    while(true){
        stack<char> stack;
        getline(cin, parenthesis);
        flag = true;
        if(parenthesis.size() == 1 && parenthesis[0] == '.') {
            return 0;
        }
        for(int j = 0; parenthesis[j] != '.'; j++) {
            if(parenthesis[j] == '(' || parenthesis[j] == '[') {
                stack.push(parenthesis[j]);
            }
            else if (parenthesis[j] == ')' || parenthesis[j] == ']') {
                if (stack.empty() || (parenthesis[j] == ')' && stack.top() != '(') || (parenthesis[j] == ']' && stack.top() != '[')) {
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
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}
