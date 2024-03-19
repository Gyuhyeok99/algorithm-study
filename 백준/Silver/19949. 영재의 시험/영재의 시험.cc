#include <iostream>
#include <vector>

using namespace std;

int ret = 0;
vector<int> a(10);
vector<int> b;
void go(int s) {
    if (b.size() == 10) {
        if (s >= 5) ret++;
        return;
    }
    for (int i = 1; i <= 5; i++) {
        int ns = s;
        if (b.size() <= 1) {
            b.push_back(i);
            if (b[b.size() - 1] == a[b.size() - 1]) {
                ns++;
            }
            go(ns);
            b.pop_back();
        }
        else {
            if (b[b.size() - 1] == i && b[b.size() - 2] == i) {
                continue;
            }
            b.push_back(i);
            if (b[b.size() - 1] == a[b.size() - 1]) {
                ns++;
            }
            go(ns);
            b.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    go(0);
    cout << ret;
}