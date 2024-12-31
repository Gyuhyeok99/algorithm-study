
#include <iostream>
#include <algorithm>
using namespace std;

int t;

int solve(int n) {
    int cnt_5 = 0;
    int cnt_2 = 0;
    for(int i = 2; i <= n; i *= 2) {
        cnt_2 += n / i;
    }
    for(int i = 5; i <= n; i *= 5) {
        cnt_5 += n / i;
    }
    return min(cnt_2, cnt_5);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}