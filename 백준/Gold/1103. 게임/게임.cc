#include <iostream>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0,- 1};
int n, m;
int arr[51][51], dp[51][51], visited[51][51];

int solve(int y, int x) {
    if(y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == -1) {
        return 0;
    }
    if(visited[y][x]) {
        cout << -1 << '\n';
        exit(0);
    }

    int& ret = dp[y][x];
    if(ret) {
        return ret;
    }

    visited[y][x] = 1;
    int value = arr[y][x];
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i] * value;
        int nx = x + dx[i] * value;
        ret = max(ret, solve(ny, nx) + 1);
    }
    visited[y][x] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < temp.size(); j++) {
            if(temp[j] == 'H') {
                arr[i][j] = -1;
            }
            else {
                arr[i][j] = temp[j] - '0';
            }
        }
    }
    cout << solve(0, 0) << '\n';
    return 0;
}