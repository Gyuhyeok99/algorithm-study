#include <iostream>
#include <queue>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, - 1};
int a[101][101], visited[101][101];
int m, n, k, s_x, s_y, e_x, e_y;
priority_queue<int, vector<int>, greater<int>> pq;

int dfs(int y, int x) {
    int ret = 1;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n)
            continue;
        if(a[ny][nx] || visited[ny][nx])
            continue;
        ret += dfs(ny, nx);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> s_x >> s_y >> e_x >> e_y;
        for(int j = s_y; j < e_y; j++) {
            for(int u = s_x; u < e_x; u++) {
                a[j][u] = 1;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!a[i][j] && !visited[i][j]) {
                pq.push(dfs(i, j));
            }
        }
    }
    cout << pq.size() << '\n';

    while(pq.size()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}