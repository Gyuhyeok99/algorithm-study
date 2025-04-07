#include <iostream>
#include <cstring>
using namespace std;

int n;
long long dp[31][31];
long long solve(int w, int h) {
    if(w < 0 || h < 0) {
        return 0;
    }
    if(w == 0 && h == 0) {
        return 1;
    }
    long long& ret = dp[w][h];
    if(ret) {
        return ret;
    }
    ret += solve(w - 1, h + 1) + solve( w, h - 1);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(1) {
        cin >> n;
        if(n == 0) {
            break;
        }
        cout << solve(n, 0) << '\n';
    }
    return 0;
}