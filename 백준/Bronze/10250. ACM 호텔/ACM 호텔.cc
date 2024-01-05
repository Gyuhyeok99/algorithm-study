#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int h, w, n;
        cin >> h >> w >> n;
        int x = n / h + 1;
        int y = n % h;
        if (y == 0) {
            y = h;
            x -= 1;
        }
        cout << y * 100 + x  << endl;
    }
    return 0;
}
