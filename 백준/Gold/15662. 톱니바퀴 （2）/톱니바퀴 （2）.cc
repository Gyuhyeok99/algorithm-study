#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int t, k, n, d, ret;
vector<deque<int>> v(1001);
int visited[1001];
vector<pair<int, int>> vv;

void isRotate(int num, int dir) {
    visited[num] = 1;
    vv.push_back({num, dir});

    if(num > 0 && !visited[num - 1]) {
        if(v[num][6] != v[num - 1][2]) {
            isRotate(num - 1, -dir);
        }
    }
    if(num < t - 1 && !visited[num + 1]) {
        if(v[num][2] != v[num + 1][6]) {
            isRotate(num + 1, -dir);
        }
    }
    return;
}

void rotateAll(int num, int dir) {
    if(dir == 1) {
        int temp = v[num].back();
        v[num].pop_back();
        v[num].push_front(temp);
    }
    else {
        int temp = v[num].front();
        v[num].pop_front();
        v[num].push_back(temp);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < temp.size(); j++) {
            v[i].push_back(temp[j] - '0');
        }
    }

    cin >> k;
    while(k--) {
        cin >> n >> d;
        n--;
        memset(visited, 0, sizeof(visited));
        vv.clear();
        isRotate(n, d);
        for(auto a : vv) {
            rotateAll(a.first, a.second);
        }
    }
    for(int i = 0; i < t; i++) {
        ret += v[i][0];
    }
    cout << ret << '\n';
    return 0;
}