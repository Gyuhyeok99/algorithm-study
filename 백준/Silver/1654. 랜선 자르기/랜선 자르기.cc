#include <iostream>
#include <algorithm>

using namespace std;

unsigned int arr[10001];
unsigned int result;
unsigned int k, n;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    unsigned int maxi = 0;

    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    unsigned int l = 1;
    unsigned int r = maxi;
    unsigned int m;

    while(l <= r) {
        m = (l + r) / 2;
        unsigned int cnt = 0;

        for(int i = 0; i < k; i++) {
            cnt += arr[i] / m;
        }

        if(cnt >= n) {
            l = m + 1;
            result = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << result << '\n';
    return 0;
}
