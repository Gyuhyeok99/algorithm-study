#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int dp[10001];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1) {
        fill(&dp[0], &dp[0] + 10001, 0);
        double temp;
        cin >> n >> temp;
        m = (int)round(temp * 100);
        if(n == 0) {
            break;
        }

        for(int i = 0; i < n; i++){
            int c; double tmp;
            cin >> c >> tmp;
            int p = (int)round(tmp * 100);
            for(int j = p; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - p] + c);
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}