#include <iostream>
#include <vector>
using namespace std;
int n;
double cake[10];

int go(int idx, double sum) {
    if(idx == n) {
        if(0.99 <= sum && sum <= 1.01) {
            return 1;
        }
        return 0;
    }
    return go(idx + 1, sum + cake[idx]) + go(idx + 1, sum);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> cake[i];
        cake[i] = 1 / cake[i];
    }
    cout << go(0, 0);
    return 0;
}
