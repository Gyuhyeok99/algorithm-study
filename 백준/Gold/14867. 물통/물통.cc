#include <iostream>
#include <map>
#include <queue>
using namespace std;

int a, b, c, d;
map<pair<int, int>, int> mp;
queue<pair<int, int>> q;

void enqueue(int x, int y, int d) {
    if(mp[{x, y}]) {
        return;
    }
    mp[{x, y}] = d + 1;
    q.push({x, y});
}
int bfs(int x, int y) {
    mp[{x, y}] = 1;
    q.push({x, y});
    while(q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        enqueue(a, y, mp[{x, y}]);
        enqueue(x, b, mp[{x, y}]);

        enqueue(0, y, mp[{x, y}]);
        enqueue(x, 0, mp[{x, y}]);

        enqueue(min(x + y, a), max(0, x + y - a), mp[{x, y}]);
        enqueue(max(0, x + y - b), min(x + y, b), mp[{x, y}]);
    }

    if(mp[{c, d}]) {
        return mp[{c, d}] - 1;
    }
    else {
        return -1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c>> d;
    cout << bfs(0, 0) << '\n';
    return 0;
}