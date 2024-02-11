#include <iostream>
#include <string.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[100004];
    int psum[100004];
    int n, k;
    int m = -10000004;
    memset(arr, 0, sizeof(arr));
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }
    for(int i = 0; i <= n - k; i++) {
        int x = psum[k + i] - psum[i];
        if(x > m) {
            m = x;
        }
    }
    cout << m;
    return 0;
}
