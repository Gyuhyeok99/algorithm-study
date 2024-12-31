#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> v[10004];
int visited[10004];
int ret[10004];
int n, m, a, b;
int h;

int dfs(int here) {
    visited[here]= 1;
    int cnt = 1;
    for(int there : v[here]) {
        if(visited[there]) {
            continue;
        }
        cnt += dfs(there);
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        ret[i] = dfs(i);
        h = max(h, ret[i]);
    }

    for(int i = 1; i <= n; i++) {
        if(ret[i] == h) {
            cout << i << ' ';
        }
    }
    return 0;
}