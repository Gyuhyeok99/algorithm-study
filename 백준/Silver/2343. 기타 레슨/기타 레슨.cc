#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ret = 987654321, l, r;
int arr[100001];

bool check(int mid) {
    int j = 0;
    for(int i = 0; i < m; i++) {
        int sum = 0;
        while(j < n) {
            if(sum + arr[j] > mid) {
                break;
            }
            sum += arr[j];
            j++;
        }
    }
    return j == n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        r += arr[i];
    }
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}
