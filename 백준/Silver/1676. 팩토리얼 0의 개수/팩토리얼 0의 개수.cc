#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0; // 2의 개수
    int b = 0; // 5의 개수
    for(int i = 2; i <= n; i++) {
        int x = i;
        while(x % 2 == 0) {
            a++;
            x /= 2;
        }
        while(x % 5 == 0) {
            b++;
            x /= 5;
        }
    }
    if(a > b) {
        cout << b << endl;
    }
    else {
        cout << a << endl;
    }

    return 0;
}
