#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int l, int h, int k) {
    while (l <= h) {
        int m = (l + h) / 2;
        if (k == arr[m]) {
            return 1;
        } else if (k < arr[m]) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[100000];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int s;
    cin >> s;
    int x;
    for(int i = 0; i < s; i++) {
        cin >> x;
        if((binarySearch(arr, 0, n - 1, x)) == 1) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

}
