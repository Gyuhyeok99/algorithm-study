#include <iostream>
#include <cstring>
using namespace std;
const int INF = 987654321;
int n, k;
int dp[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(dp, dp + 10001, INF);
    cin >> n >> k;
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        for(int j = temp; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - temp] + 1);
        }
    }
    if(dp[k] == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[k] << '\n';
    }
    return 0;
}