#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, x1, _y1, x2, y2, y, x, ret;
char arr[301][301];
int visited[301][301];
queue<pair<int, int>>q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> _y1 >> x1 >> y2 >> x2;
    _y1--, x1--, y2--, x2--;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    q.push({_y1, x1});
    visited[_y1][x1] = 1;
    while(arr[y2][x2] != '0') {
        ret++;
        queue<pair<int, int>> temp;
        while(q.size()) {
            tie(y, x) = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) {
                    continue;
                }
                visited[ny][nx] = ret;
                if(arr[ny][nx] != '0') {
                    arr[ny][nx] = '0';
                    temp.push({ny,nx});
                }else {
                    q.push({ny, nx});
                }
            }
        }
        q = temp;
    }
    cout << ret << '\n';
}