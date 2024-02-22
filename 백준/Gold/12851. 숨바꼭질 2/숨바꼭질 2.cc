#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000;
int n, k, visited[MAX + 4], cnt[MAX + 4];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    if(n == k) {
        cout << 0 << '\n' << 1 << '\n';
        return 0;
    }
    visited[n] = 1;
    q.push(n);
    cnt[n] = 1;
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int next : {x + 1, x - 1, 2 * x}) {
            if(next < 0 || next > MAX) {
                continue;
            }
            if(visited[next] == 0) {
                q.push(next);
                visited[next] = visited[x] + 1;
                cnt[next] += cnt[x];
            }
            else if(visited[next] == visited[x] + 1) {
                cnt[next] += cnt[x];
            }
        }
    }
    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
    return 0;
}