#include <iostream>
using namespace std;

int arr[9][9];
int n, m, ret = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            ret = max(ret, arr[i][j]);
            if(ret == arr[i][j]) {
                n = i;
                m = j;
            }
        }
    }
    cout << ret << '\n';
    cout << n + 1 << ' ' << m + 1<< '\n';
    return 0;
}