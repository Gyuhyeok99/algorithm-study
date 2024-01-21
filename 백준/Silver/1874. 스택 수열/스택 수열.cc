#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int n;
    vector<char> v;
    int c = 1;

    s.push(0);
    bool flag = true;
    cin >> n;
    int num;
    for(int i = 0; i < n; i++) {
        cin >> num;
        while(s.top() < num) {
            s.push(c);
            c++;
            v.push_back('+');
        }
        if(s.top() == num) {
            s.pop();
            v.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
