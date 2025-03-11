#include <iostream>
using namespace std;

int n, m , a[100005], mx, ret, l, h;

bool check(int mid) {
    int cnt = 1, temp = mid;
    for(int i = 0; i < n; i++) {
        if(mid - a[i] < 0) {
            mid = temp;
            cnt++;
        }
        mid -= a[i];
    }
    return cnt <= m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    l = mx, h = 1000000004;
    while(l <= h) {
        int mid = (l + h) / 2;
        if(check(mid)) {
            h = mid - 1;
            ret = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}