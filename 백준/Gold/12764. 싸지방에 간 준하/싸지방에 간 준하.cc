#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, ret;
vector<pair<int, int>> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> seats;
int ans[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        while(pq.size()) {
            if(pq.top().first <= v[i].first) {
                seats.push(pq.top().second);
                pq.pop();
            }
            else {
                break;
            }
        }
        if(seats.empty()) {
            pq.push({v[i].second, ret});
            ans[ret++]++;
        }
        else {
            int tmp = seats.top();
            pq.push({v[i].second, tmp});
            ans[tmp]++;
            seats.pop();
        }
    }
    cout << ret << '\n';
    for(int i = 0; i < ret; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}