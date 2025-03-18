#include <iostream>
#include <queue>
using namespace std;

int n;
int dp[1000004];
int INF = 987654321;

void solve(int here) {
    if(here == 0) {
        return;
    }
    cout << here << ' ';
    if(here % 3 == 0 && dp[here] == (dp[here / 3] + 1)) {
        solve(here / 3);
    }
    else if(here % 2 == 0 && dp[here] == (dp[here / 2] + 1)) {
        solve(here / 2);
    }
    else if(here - 1 >= 0 && (dp[here] == (dp[here - 1] + 1))) {
        solve(here - 1);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(dp, dp + 1000004, INF);

    dp[1] = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(!(i % 3)) {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
        if(!(i % 2)) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }
    cout << dp[n] << '\n';
    solve(n);
    return 0;
}