#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int t, n;
string p, a;

void print(deque<int>& dq) {
    cout << '[';
    while(dq.size()) {
        cout << dq.front();
        dq.pop_front();
        if(dq.size()) {
            cout << ',';
        }
    }
    cout << ']' << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> p >> n >> a;
        bool isReverse = false;
        bool isError = false;
        deque<int> dq;
        string temp = "";
        for(int i = 1; i < a.size() - 1; i++) {
            if(isdigit(a[i])) {
                temp += a[i];
            }
            else {
                if(temp.size()) {
                    dq.push_back(atoi(temp.c_str()));
                    temp = "";
                }
            }
        }
        if(temp.size()) {
            dq.push_back(atoi(temp.c_str()));
        }
        for(int i = 0; i < p.size(); i++) {
            if(p[i] == 'R') {
                isReverse = !isReverse;
            }
            else {
                if(dq.empty()) {
                    isError = true;
                    break;
                }
                else {
                    if(isReverse) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
        }
        if(isError) {
            cout << "error" << '\n';
        }
        else {
            if(isReverse) {
                reverse(dq.begin(), dq.end());
            }
            print(dq);
        }
    }
    return 0;
}