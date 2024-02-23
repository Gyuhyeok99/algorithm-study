#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, ret, visited[200004], _prev[200004];
queue<int> q;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    q.push(n);
    visited[n] = 1;
    while(q.size()) {
        int x = q.front(); q.pop();
        if(x == k) {
            ret = visited[k];
            break;
        }
        for(int nx : {x - 1, x + 1, x * 2}) {
            if(nx < 0 || nx >= 200004 || visited[nx]) {
                continue;
            }
            visited[nx] = visited[x] + 1;
            _prev[nx] = x;
            q.push(nx);
        }
    }
    for(int i = k; i != n; i = _prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    reverse(v.begin(), v.end());
    cout << ret - 1 << '\n';
    for(int i : v) {
        cout << i << ' ';
    }
    return 0;
}
