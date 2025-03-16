#include <iostream>
#include <algorithm>

using namespace std;

long long x, y, z, l = 1, r, ret = 1e18;

bool check(long long mid) {
    long long change = (mid + y)  * 100 / (mid + x);
    if(z != change) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y;
    if(x == y) {
        cout << -1 << '\n';
        return 0;
    }
    r = 1e9;
    z = (y * 100) / x;
    while(l <= r) {
        long long mid = (r + l) / 2;
        if(check(mid)) {
            ret = mid;
            r = mid -1;
        }
        else {
            l = mid + 1;
        }
    }
    if(ret == 1e18) {
        cout << -1 << '\n';
    }
    else {
        cout << ret << '\n';
    }
    return 0;
}