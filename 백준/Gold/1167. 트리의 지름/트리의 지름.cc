#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v, ret, leaf, visited[100001];
vector<pair<int, int>> adj[100001];
void dfs(int here, int cnt) {
    if(ret < cnt) {
        leaf = here;
        ret = cnt;
    }
    for(auto there : adj[here]) {
        if(visited[there.first]) {
            continue;
        }
        visited[there.first] = 1;
        dfs(there.first, cnt + there.second);
        visited[there.first] = 0;
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> v;
    for(int i = 1; i <= v; i++) {
        int s, e, c;
        cin >> s;
        while(true) {
            cin >> e;
            if(e == -1) {
                break;
            }
            cin >> c;
            adj[s].push_back({e, c});
        }
    }
    visited[1] = 1;
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    ret = 0;
    visited[leaf] = 1;
    dfs(leaf, 0);
    cout << ret;
    return 0;
}
