#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ret;
int arr[17][17], dp[17][17][3];

bool check(int y, int x, int dir) {
    if(dir == 0 || dir == 2) {
        if(arr[y][x]) {
            return false;
        }
    }
    else {
        if(arr[y][x] || arr[y - 1][x] || arr[y][x - 1]) {
            return false;
        }
    }
    return true;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][1][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(check(i, j + 1, 0)) {
                dp[i][j + 1][0] += dp[i][j][0];
            }
            if(check(i + 1, j + 1, 1)) {
                dp[i + 1][j + 1][1] += dp[i][j][0];
            }

            if(check(i + 1, j, 2)) {
                dp[i + 1][j][2] += dp[i][j][2];
            }
            if(check(i + 1, j + 1, 1)) {
                dp[i + 1][j + 1][1] += dp[i][j][2];
            }

            if(check(i, j + 1, 0)) {
                dp[i][j + 1][0] += dp[i][j][1];
            }
            if(check(i + 1, j, 2)) {
                dp[i + 1][j][2] += dp[i][j][1];
            }
            if(check(i + 1, j + 1, 1)) {
                dp[i + 1][j + 1][1] += dp[i][j][1];
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        ret += dp[n - 1][n - 1][i];
    }
    cout << ret << '\n';
    return 0;
}