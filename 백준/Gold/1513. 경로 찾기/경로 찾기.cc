#include <iostream>
#include <cstring>
using namespace std;

int n, m, c;
int arr[51][51], dp[51][51][51][51];
int mod = 1000007;
int solve(int y, int x, int cnt, int prev) {
    if(y >= n || x >= m) {
        return 0;
    }
    if(y == n - 1 && x == m - 1) {
        if(cnt == 0 && arr[y][x] == 0) {
            return 1;
        }
        if(cnt == 1 && arr[y][x] > prev) {
            return 1;
        }
        return 0;
    }

    int& ret = dp[y][x][cnt][prev];

    if(ret != -1) {
        return ret;
    }
    ret = 0;
    if(arr[y][x] == 0) {
        ret = (solve(y + 1, x, cnt, prev) + solve(y, x + 1, cnt, prev)) % mod;
    }
    else if(arr[y][x] > prev) {
        ret = (solve(y + 1, x, cnt - 1, arr[y][x]) + solve(y, x + 1, cnt - 1, arr[y][x])) % mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&dp[0][0][0][0], &dp[0][0][0][0] + 51 * 51 * 51 * 51, -1);
    cin >> n >> m >> c;
    for(int i = 1; i <= c; i++) {
        int y, x;
        cin >> y >> x;
        y--, x--;
        arr[y][x] = i;
    }

    for(int i = 0; i <= c; i++) {
        cout << solve(0, 0, i, 0) << " ";
    }
    return 0;
}