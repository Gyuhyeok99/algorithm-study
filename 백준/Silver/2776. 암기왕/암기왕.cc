#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, m;
int a[1000001], b[1000001];

bool check(int num) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid] == num) {
            return true;
        }
        else if(a[mid] > num) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);

        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        for(int i = 0; i < m; i++) {
            if(check(b[i])) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}