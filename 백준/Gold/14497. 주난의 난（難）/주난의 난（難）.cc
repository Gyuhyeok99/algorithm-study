#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
const int MAX = 304;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, x, y, _x1, _y1, _x2, _y2, ret, visited[MAX][MAX];
char a[MAX][MAX];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> _y1 >> _x1 >> _y2 >> _x2;
    _y1--; _x1--; _y2--; _x2--;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    visited[_y1][_x1] = 1;
    q.push({_y1, _x1});
    while(a[_y2][_x2] != '0') {
        ret++;
        queue<pair<int, int>> temp;
        while(q.size()) {
            tie(y, x) = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = ret;
                if(a[ny][nx] != '0') {
                    a[ny][nx] = '0';
                    temp.push({ny, nx});
                }
                else {
                    q.push({ny, nx});
                }
            }
        }
        q = temp;
    }
    cout << visited[_y2][_x2] << '\n';
    return 0;
}
