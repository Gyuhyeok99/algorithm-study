#include <iostream>
#include <queue>
using namespace std;
int n, k, visited[200004];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if(n == k) {
        cout << 0 << '\n';
        return 0;
    }
    q.push(n);
    visited[n] = 1;
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int nx : {x + 1, x - 1, 2 * x}) {
            if(nx >= 200004 || nx < 0) {
                continue;
            }
            if(visited[nx] == 0) {
                visited[nx] = visited[x] + 1;
                q.push(nx);
                if(nx == k) {
                    cout << visited[k] - 1 << '\n';
                    return 0;
                }
            }

        }
    }
    return 0;
}
