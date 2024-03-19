#include <iostream>
using namespace std;
int n;
int a[21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i <= 20; i++) {
        if(i == 0) {
            a[i] = 0;
        }
        else if(i == 1) {
            a[i] = 1;
        }
        else {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    cout << a[n];
    return 0;
}
