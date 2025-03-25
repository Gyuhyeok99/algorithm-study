#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int arr[101][101], visited[101][101], cnt, ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x) {
    visited[y][x] = 1;
    if(arr[y][x] == 1) {
        cnt++;
        arr[y][x] = 0;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
            continue;
        }
        if(visited[ny][nx]) {
            continue;
        }
        dfs(ny,  nx);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while(1) {
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        dfs(0, 0);
        bool flag = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 1) {
                    flag = false;
                    break;
                }
            }
        }
        ret++;
        if(flag) {
            break;
        }
    }
    cout << ret << '\n' << cnt << '\n';
    return 0;
}