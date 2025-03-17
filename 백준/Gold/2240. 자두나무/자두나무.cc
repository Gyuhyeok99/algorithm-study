#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, w;
int a[1001];
int dp[1001][2][31];
int solve(int idx, int tree, int cnt) {
    if(cnt < 0) {
        return -1e9;
    }
    if(idx == t) {
        return 0;
    }
    int& ret = dp[idx][tree][cnt];
    if(ret != -1) {
        return ret;
    }
    return ret = max(solve(idx + 1, tree ^ 1, cnt - 1),
                     solve(idx + 1, tree, cnt)) + (tree == a[idx] - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&dp[0][0][0], &dp[0][0][0] + 1001 * 2 * 31, -1);
    cin >> t >> w;
    for(int i = 0; i < t; i++) {
        cin >> a[i];
    }
    cout << max(solve(0, 1, w - 1), solve(0, 0, w)) << '\n';
    return 0;
}