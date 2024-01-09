#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, idx;
    int arr[10001] {};
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> idx;
        arr[idx]++;
    }
    for(int i = 1; i <= 10000; i++) {
        for(int j = 1; j <= arr[i]; j++) {
            cout << i << "\n";
        }
    }
    return 0;
}