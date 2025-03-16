#include <iostream>
#include <algorithm>

using namespace std;

long long INF = 1e18;

struct Room {
    int t, a, h;
} room[123460];

long long l = 1, r = INF, ret = INF;
int n, h;

bool check(long long mid, long long atk) {
    long long maxHp = mid;
    long long curHp = mid;
    for(int i = 0; i < n; i++) {
        if(room[i].t == 1) {
            // 몬스터방
            long long cnt = room[i].h / atk;
            if(room[i].h % atk == 0) {
                cnt--;
            }
            curHp -= cnt * room[i].a;
            if(curHp <= 0) {
                return false;
            }
        }
        else {
            // 회복방
            atk += room[i].a;
            curHp += room[i].h;
            if(curHp > maxHp) {
                curHp = maxHp;
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        cin >> room[i].t >> room[i].a >> room[i].h;
    }

    while(l <= r) {
        long long mid = (l + r) / 2;
        if(check(mid, h)) {
            ret = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret << '\n';
    return 0;
}