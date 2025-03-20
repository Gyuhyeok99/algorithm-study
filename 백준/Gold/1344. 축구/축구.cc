#include <iostream>
#include <cstring>
using namespace std;

int n = 18;
bool isP[20];
double a, b, dp[20][20][20];

void era() {
    fill(isP, isP + 20, 1);
    isP[0] = 0;
    isP[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(isP[i] == 0) {
            continue;
        }
        for(int j = i * 2; j <= n; j += i) {
            isP[j] = 0;
        }
    }
}

double solve(int idx, int x, int y) {
    if(idx == n) {
        if(isP[x] || isP[y]) {
            return 1.0;
        }
        else {
            return 0.0;
        }
    }

    double& ret = dp[idx][x][y];
    if(ret > -0.5) {
        return ret;
    }
    ret = 0.0;

    ret += solve(idx + 1, x + 1, y) * a * (1 - b);
    ret += solve(idx + 1, x, y + 1) * (1 - a) * b;
    ret += solve(idx + 1, x + 1, y + 1) * a * b;
    ret += solve(idx + 1, x, y) * (1 - a) * (1 - b);

    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    a /= 100; b /= 100;
    era();
    cout << solve(0, 0, 0) << '\n';
    return 0;
}