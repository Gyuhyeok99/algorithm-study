#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, ret = 987654321;
int arr[21][21];

int go(vector<int>& a, vector<int>& b) {
    int sumA = 0, sumB = 0;
    for(int i = 0; i < n / 2; i++) {
        for(int j = 0; j < n / 2; j++) {
            if(i == j) {
                continue;
            }
            sumA += arr[a[i]][a[j]];
            sumB += arr[b[i]][b[j]];
        }
    }
    return abs(sumA - sumB);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        if(__builtin_popcount(i) != (n / 2)) {
            continue;
        }
        vector<int> a, b;
        for(int j = 0; j < n; j++) {
            if(i & 1 << j) {
                a.push_back(j);
            }
            else {
                b.push_back(j);
            }
        }
        ret = min(ret, go(a, b));
    }
    cout << ret << '\n';
    return 0;
}