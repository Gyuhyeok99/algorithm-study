#include <iostream>
#include <queue>
using namespace std;

int main() {

    int n;
    int k;
    cin >> n >> k;
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    cout << '<';
    while(q.size() > 1) {
        for(int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << '>';

    return 0;
}