#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<vector<int>> v;
int n, m, temp;
int result = 987654321;

void combi(int start, vector<int> b) {
    if(b.size() == m) {
        v.push_back(b);
        return;
    }
    for(int i = start + 1; i < chicken.size(); i++) {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int solve(pair<int, int> h, int c) {
    return abs(chicken[c].first - h.first) + abs(chicken[c].second - h.second);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> temp;
            if(temp == 1) {
                home.push_back({i, j});
            }
            else if(temp == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    vector<int> b;
    combi(-1, b);

    for(vector<int> select : v) {
        int ret = 0;
        for(auto h : home) {
            int t = 987654321;
            for(int c : select) {
                t = min(t, solve(h, c));
            }
            ret += t;
        }
        result = min(result, ret);
    }
    cout << result << '\n';
    return 0;
}