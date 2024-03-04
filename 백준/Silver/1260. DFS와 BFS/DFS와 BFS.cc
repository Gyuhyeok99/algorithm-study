#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, v, a, b;
vector<int> adj[1001];
int visited[1001];
void dfs(int here) {
    visited[here] = 1;
    cout << here << ' ';
    for(int there : adj[here]) {
        if(visited[there]) {
            continue;
        }
        dfs(there);
    }
}
void bfs(int here) {
    queue<int> q;
    q.push(here);
    visited[here] = 1;
    while(q.size()) {
        int _next = q.front();
        cout << _next << ' ';
        visited[_next] = 1;
        q.pop();
        for(int there : adj[_next]) {
            if(visited[there]) {
                continue;
            }
            visited[there] = visited[_next] + 1;
            q.push(there);
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    cout << '\n';
    memset(visited, 0, sizeof(visited));
    bfs(v);

    return 0;
}
