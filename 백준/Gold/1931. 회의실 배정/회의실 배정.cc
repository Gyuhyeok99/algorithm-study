#include <iostream>
#include <queue>
using namespace std;

int n, s, e, ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while(n--) {
        cin >> s >> e;
        pq.push({e, s});
    }
    e = pq.top().first;
    s = pq.top(). second;
    pq.pop();
    ret++;
    while(pq.size()) {
        int en = pq.top().first;
        int st = pq.top().second;
        pq.pop();
        if(st >= e) {
            e = en;
            s = st;
            ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}