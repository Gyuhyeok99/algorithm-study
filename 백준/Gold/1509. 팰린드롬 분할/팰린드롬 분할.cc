#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int INF = 987654321;
string s;
int n;
int dp[2501][2501], dp2[2501];
int solve(int idx) {
    if(idx == n) {
        return 0;
    }

    int& ret = dp2[idx];
    if(ret != INF) {
        return ret;
    }
    for(int i = 0; i <= n - idx; i++) {
        if(dp[idx][idx + i]) {
            ret = min(ret, solve(idx + i + 1) + 1);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(dp2, dp2 + 2501, INF);
    cin >> s;
    n = s.size();
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(s[j] == s[j + i] && dp[j + 1][j + i - 1]) {
                dp[j][j + i] = 1;
            }
        }
    }
    cout << solve(0) << '\n';
    return 0;
}