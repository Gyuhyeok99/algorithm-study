#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int arr[4];
int n, ret_max = -1000000001, ret_min = 1000000001;
int cal(int a, int b, int c) {
    if(c == 0) {
        return a + b;
    }
    else if(c == 1) {
        return a - b;
    }
    else if(c == 2) {
        return a * b;
    }
    else if(c == 3) {
        return a / b;
    }
    return -1;
}

void go(int idx, int sum) {
    if(idx == n - 1) {
        ret_max = max(ret_max, sum);
        ret_min = min(ret_min, sum);
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(arr[i] == 0) {
            continue;
        }
        arr[i]--;
        go(idx + 1,cal(sum, v[idx + 1], i));
        arr[i]++;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    go(0, v[0]);
    cout << ret_max << '\n';
    cout << ret_min << '\n';
    return 0;
}