#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n, m;
int a[3], b[3];

int solve(int idx, int sum, int prev) {
    if(idx == n) {
        if(sum >= m) {
            return 1;
        }
        return 0;
    }
    int ret = 0;

    for(int i = 0; i < 6; i++) {
        if(i < 3) {
            if(prev == i) {
                ret += solve(idx + 1, sum + (a[i] / 2), i);
            }
            else {
                ret += solve(idx + 1, sum + a[i], i);
            }
        }
        else {
            if(prev == i % 3) {
                ret += solve(idx + 1, sum + (b[i % 3] / 2), i % 3);
            }
            else {
                ret += solve(idx + 1, sum + b[i % 3], i % 3);
            }
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 3; i++) {
        cin >> b[i];
    }

    cout << solve(0, 0, -1) << '\n';
    return 0;
}