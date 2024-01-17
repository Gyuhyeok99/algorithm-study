#include <iostream>
#include <stack>

using namespace std;
int main() {

    stack<int> s;
    int k;
    cin >> k;
    int sum = 0;
    int n;
    for(int i = 0; i < k; i++) {
        cin >> n;
        if(n == 0) {
            sum -= s.top();
            s.pop();
        }
        else {
            sum += n;
            s.push(n);
        }
    }
    cout << sum << '\n';
    return 0;
}
