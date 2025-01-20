#include <iostream>
#include <queue>
using namespace std;
int n, k;
int visited[200002], cnt[200002];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if(n == k) {
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while(q.size()) {
        int x = q.front();
        q.pop();
        for(int nx : {x - 1, x + 1, 2 * x}) {
            if(nx < 0 || nx >= 200002) {
                continue;
            }
            if(!visited[nx]) {
                q.push(nx);
                visited[nx] = visited[x] + 1;
                cnt[nx] += cnt[x];
            }
            else if(visited[nx] == visited[x] + 1) {
                cnt[nx] += cnt[x];
            }
        }
    }
    cout << visited[k] - 1 << '\n' << cnt[k] << '\n';
    return 0;
}