#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    bool* isPrime = new bool[n + 1];
    for(int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = max(2, m); i <= n; i++) {
        if(isPrime[i]) {
            cout << i << '\n';
        }
    }
    delete[] isPrime;
    return 0;

}
