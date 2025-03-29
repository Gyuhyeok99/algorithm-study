#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int n, s, e, sum;
long long ret;
int arr[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> sum;
    sort(arr, arr + n);
    e = n - 1;
    while(s < e) {
        if(arr[s] + arr[e] == sum) {
            ret++;
            e--;
        }
        else if(arr[s] + arr[e] > sum) {
            e--;
        }
        else {
            s++;
        }
    }
    cout << ret << '\n';

    return 0;
}
