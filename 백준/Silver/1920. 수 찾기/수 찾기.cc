#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num;
int a[100001];

bool find(int num, int l, int r) {
    while(l <= r) {
        int mid = (l + r) / 2;
        if(num == a[mid]) {
            return true;
        }
        else if(num > a[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> num;
        if(find(num, 0, n - 1)) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}