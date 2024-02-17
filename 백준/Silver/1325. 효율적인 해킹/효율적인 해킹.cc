#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, m, a, b, ret;
vector<int> v[10001];
bool visited[10001];
vector<int> cnt;
int dfs(int x) {
    visited[x] = 1;
    int cnt = 1;
    for (int there : v[x]) {
        if (!visited[there]) {
            cnt += dfs(there);
        }
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
        memset(visited, false, sizeof(visited));
        int temp = dfs(i);
        if(ret < temp) {
            cnt.clear();
            cnt.push_back(i);
        }
        else if(ret == temp) {
            cnt.push_back(i);
        }
        ret = max(ret, temp);

    }
    for(int i : cnt) {
        cout << i << ' ';
    }
    return 0;
}
