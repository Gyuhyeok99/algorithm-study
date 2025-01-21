#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define y1 aaaa
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, x1, x2, y1, y2, x, y, ret, visited[301][301];
char a[301][301];
queue<pair<int, int>> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--, x2--, y1--, y2--;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    q.push({y1, x1});
    visited[y1][x1] = 1;
    while(a[y2][x2] != '0') {
        ret++;
        queue<pair<int, int>> temp;
        while(q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = ret;
                if (a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push({ny, nx});
                } else {
                    q.push({ny, nx});
                }
            }
        }
        q = temp;
    }
    cout << visited[y2][x2] << '\n';
    return 0;
}