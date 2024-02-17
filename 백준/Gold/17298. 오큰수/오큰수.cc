#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

stack<int> s;
int n, a[1000001], ret[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i]) {
            ret[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    for(int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    }
    return 0;
}