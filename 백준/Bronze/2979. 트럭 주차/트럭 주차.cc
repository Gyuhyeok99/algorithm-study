#include <iostream>
#include <string.h>

using namespace std;
int a[101];
int A, B, C;
int x, y;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    memset(a, 0, sizeof(a));
    cin >> A >> B >> C;
    for(int i = 0; i < 3; i++) {
        cin >> x >> y;
        for(int j = x; j < y; j++) {
            a[j]++;
        }
    }
    int sum = 0;
    for(int i = 0; i < 101; i++) {
        if(a[i] == 1) {
            sum += A;
        }
        else if(a[i] == 2) {
            sum += B * 2;
        }
        else if(a[i] == 3) {
            sum += C * 3;
        }
    }
    cout << sum << '\n';

    return 0;
}
