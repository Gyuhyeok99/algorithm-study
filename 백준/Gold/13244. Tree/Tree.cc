#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m, x, y;
int visited[1004];
bool flag;
vector<int> v[1004];
void dfs(int node, int parent) {
    visited[node] = 1;
    for(int neighbor : v[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, node);
        }
        else {
            if(neighbor != parent) {
                flag = false;
                return;
            }
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;

        flag = true;
        memset(visited, 0, sizeof(visited));
        for(int j = 0; j <= n; j++) {
            v[j].clear();
        }

        for(int j = 0; j < m; j++) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        if(n - m != 1) {
            cout << "graph" << '\n';
            continue;
        }

        dfs(x, -1);

        for(int j = 1; j <= n; j++) {
            if( !visited[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "tree" << '\n';
        }
        else {
            cout << "graph" << '\n';
        }
    }
    return 0;
}