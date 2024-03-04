#include <iostream>
#include <vector>
using namespace std;
int n, m, u, v, ret, visited[10004];
vector<int> adj[10004];
void dfs(int here) {
    visited[here] = 1;
    for(int there : adj[here]) {
        if(visited[there]) {
            continue;
        }
        dfs(there);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++)  {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            dfs(i);
            ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}
