#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int n, c;
map<int, int> mp1, mp2;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return mp2[a.first] < mp2[b.first];
    }
    return a.second > b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for(int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        mp1[x]++;
        if(mp2[x] == 0) {
            mp2[x] = i + 1;
        }

    }
    for(auto temp : mp1) {
        v.push_back({temp.first, temp.second});
    }
    sort(v.begin(), v. end(), cmp);
    for(auto temp : v) {
        for(int i = 0; i < temp.second; i++) {
            cout << temp.first << ' ';
        }
    }
    return 0;
}