#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long n, m, v, k, c, ret;
vector<pair<int, int>> bo;
vector<int> bag;
priority_queue<int> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> m >> v;
        bo.push_back({m, v});
    }

    for(int i = 0; i < k; i++) {
        cin >> c;
        bag.push_back(c);
    }

    sort(bo.begin(), bo.end());
    sort(bag.begin(), bag.end());

    int j = 0;
    for(int i = 0; i < k; i++) {
        while(j < n && bag[i] >= bo[j].first) {
            pq.push(bo[j++].second);
        }
        if(pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';
    return 0;
}
