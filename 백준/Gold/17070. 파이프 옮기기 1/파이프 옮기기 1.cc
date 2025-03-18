#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int a[21][21], dp[21][21][3];
bool check(int y, int x, int d) {
    if(d == 0 || d == 2) {
        if(!a[y][x]) {
            return true;
        }
    }
    else if(d == 1) {
        if(a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) {
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    dp[1][2][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][0];

            if(check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][2];
            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][2];

            if(check(i, j + 1, 0))dp[i][j + 1][0] += dp[i][j][1];
            if(check(i + 1, j, 2))dp[i + 1][j][2] += dp[i][j][1];
            if(check(i + 1, j + 1, 1))dp[i + 1][j + 1][1] += dp[i][j][1];
        }
    }

    int ret = 0;
    for(int i = 0; i < 3; i++) {
        ret += dp[n][n][i];
    }
    cout << ret << '\n';
    return 0;
}