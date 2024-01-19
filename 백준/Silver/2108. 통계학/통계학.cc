#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    vector<int> v;
    int n;
    int sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    double avg = static_cast<double>(sum) / n;
    int intavg = round(avg);
    avg = round(avg * 10.0)/10.0;
    int scope = v[n - 1] - v[0];
    int median = v[n/2];

    int cnt[8001] = {0};
    for(int i = 0; i < n; i++) {
        if(v[i] >= 0) {
            cnt[v[i]]++;
        }
        else {
            cnt[-v[i] + 4000]++;
        }
    }
    int max = cnt[0];
    int idx = 0;
    for(int i = 0; i < 8001; i++) {
        if(max <cnt[i]) {
            idx = i;
            max = cnt[i];
        }
    }
    vector<int> md;
    for(int i = 0; i < 8001; i++) {
        if(max == cnt[i]) {
            if(i <= 4000) {
                md.push_back(i);
            }
            else {
                md.push_back((i - 4000) * -1);
            }
        }
    }
    int mode;
    sort(md.begin(), md.end());
    if(md.size() == 1) {
        mode = md[0];
    }
    else {
        mode = md[1];
    }

    cout << intavg << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << scope << endl;
    return 0;
}
