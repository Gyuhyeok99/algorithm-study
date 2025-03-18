#include <iostream>
using namespace std;

int n;
long long dp[31][31];

long long solve(int a, int b) {
    if(a == 0 && b == 0) {
        return 1;
    }

    if(dp[a][b]) {
        return dp[a][b];
    }
    long long & ret = dp[a][b];
    if(a > 0) {
        ret += solve(a - 1, b + 1);
    }
    if(b > 0) {
        ret += solve(a, b - 1);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> n;
        if(n == 0) {
            break;
        }
        cout << solve(n, 0) << '\n';
    }
    return 0;
}