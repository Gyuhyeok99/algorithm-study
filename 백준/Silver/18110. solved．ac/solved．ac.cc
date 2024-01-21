#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double n;
    cin >> n;
    double trimmed_mean = round(n * 0.15);
    if(n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<double> v;
    for(int i = 0; i < n; i++) {
        double x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    double sum = 0;
    for(int i = 0; i < (n - (trimmed_mean * 2)); i++) {
        sum += v[i + trimmed_mean];
    }
    cout << round(sum / (n - (trimmed_mean * 2))) << '\n';
    return 0;
}
