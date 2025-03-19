#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if(abs(a) == abs(b)) {
            return a > b;
        }
        return  abs(a) > abs(b);
    }
};

int n;
priority_queue<int, vector<int>, cmp> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        if(num == 0) {
            if(pq.size()) {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            pq.push(num);
        }
    }
    return 0;
}