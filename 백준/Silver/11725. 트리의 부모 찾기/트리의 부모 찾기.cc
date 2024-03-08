#include <iostream>
#include <vector>
using namespace std;
int n, u, v, visited[100002], par[100002];
vector<int> adj[100002];
void dfs(int here) {
    visited[here] = 1;
    for(int there : adj[here]) {
        if(visited[there]) {
            continue;
        }
        par[there] = here;
        dfs(there);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 2; i <= n; i++) {
        cout << par[i] << '\n';
    }
    return 0;
}
