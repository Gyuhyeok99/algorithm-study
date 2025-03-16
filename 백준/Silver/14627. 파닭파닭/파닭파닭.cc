#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long s, c, l = 1, r = 1000000000, len;
int a[1000001];
long long ret, sum;

bool check(int mid) {
    long long cnt = 0;
    for(int i = 0; i < s; i++) {
        cnt += a[i] / mid;
    }
    return cnt >= c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> c;
    for(int i = 0; i < s; i++) {
        cin >> a[i];
        sum += a[i];
    }
    while(l <= r) {
        long long  mid = (l + r) / 2;
        if(check(mid)) {
            len = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    ret = sum - (c * len);
    cout << ret << '\n';
    return 0;
}