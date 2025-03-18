#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int dp[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[0] = 1;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        for(int j = temp; j <= k; j++) {
            dp[j] += dp[j - temp];
        }
    }
    cout << dp[k] << '\n';
    return 0;
}