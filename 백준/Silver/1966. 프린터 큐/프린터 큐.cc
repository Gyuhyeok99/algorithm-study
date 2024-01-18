#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        int n, m;
        cin >> n >> m;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            pq.push(x);
            q.push(pair<int, int>(j, x));
        }
        int count = 0;
        while(!(q.empty())) {
            int idx = q.front().first;
            int priority = q.front().second;
            q.pop();
            if(priority == pq.top()) {
                count++;
                pq.pop();
                if(idx == m) {
                    cout << count << '\n';
                    break;
                }
            }
            else {
                q.push(pair<int, int>(idx, priority));
            }
        }
    }
    return 0;
}
