#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int arr[100];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum, max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                sum = arr[i] + arr[j] + arr[k];
                if(sum > max && sum <= m) {
                    max = sum;
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}
