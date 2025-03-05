#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 987654321;

int n, k;
int arr[21][21];
int ret = INF;

int getSum(vector<int> sums) {
    int sum = 0;
    for(int i : sums) {
        for(int j : sums) {
            if(i == j) {
                continue;
            }
            sum += arr[i][j];
        }
    }
    return sum;
}

void combi(int start, vector<int> selectedA) {
    if(ret == 0) {
        return;
    }
    if(selectedA.size() == k) {
        vector<int> selectedB;
        for(int i = 0; i < n; i++) {
            if(find(selectedA.begin(), selectedA.end(), i) == selectedA.end()) {
                selectedB.push_back(i);
            }
        }
        int a = getSum(selectedA);
        int b = getSum(selectedB);
        ret = min(abs(a - b), ret);
        return;
    }

    for(int i = start + 1; i < n; i++) {
        selectedA.push_back(i);
        combi(i, selectedA);
        selectedA.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    k = n / 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>> arr[i][j];
        }
    }
    combi(-1, {});

    cout << ret << '\n';
    return 0;
}