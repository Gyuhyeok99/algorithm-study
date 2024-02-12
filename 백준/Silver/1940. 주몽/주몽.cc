#include <iostream>
#include <string.h>
using namespace std;

int n, m;
int arr[15004];
int cnt;
void combi() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] + arr[j] == m) {
                cnt++;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    combi();
    cout << cnt << '\n';
    return 0;
}
