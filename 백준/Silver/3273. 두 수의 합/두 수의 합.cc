#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
long long arr[100000];
long long s, e, ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    sort(arr, arr + n);
    e = n - 1;
    while(s < e) {
        if(arr[s] + arr[e] == x) {
            ret++;
            e--;
        }
        else if (arr[s] + arr[e] > x) {
            e--;
        }
        else {
            s++;
        }
    }
    cout << ret << '\n';
    return 0;
}