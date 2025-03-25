#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int, int> mp1, mp2;
vector<pair<int, int>> v;
int n, m;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return mp2[a.first] < mp2[b.first];
    }
    return a.second > b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        mp1[num]++;
        if(mp2[num] == 0) {
            mp2[num] = i;
        }
    }

    for(auto a : mp1) {
        v.push_back({a.first, a.second});
    }
    sort(v.begin(), v.end(), cmp);

    for(auto a : v) {
        for(int i = 0; i < a.second; i++) {
            cout << a.first << ' ';
        }
    }
    return 0;
}