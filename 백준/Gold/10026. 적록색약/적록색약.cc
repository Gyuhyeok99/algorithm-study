#include <iostream>
#include <cstring>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, retA, retB, visited[101][101];
char a[101][101];
void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] != a[y][x] || visited[ny][nx]) {
            continue;
        }
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 0) {
                dfs(i, j);
                retA++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 'G') {
                a[i][j] = 'R';
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 0) {
                dfs(i, j);
                retB++;
            }
        }
    }
    cout << retA << ' ' << retB << '\n';
    return 0;
}
