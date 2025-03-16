#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int n;
int lis[1000001], len, num;
stack<int> st;
pair<int, int> ans[1000001];
const int INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    fill(lis, lis + 1000001, INF);
    for(int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = lowerPos - lis;
        if(*lowerPos == INF) {
            len++;
        }
        *lowerPos = num;
        ans[i].first = _pos;
        ans[i].second = num;
    }

    cout << len << '\n';
    for(int i = n - 1; i >= 0; i--) {
        if(ans[i].first == len - 1) {
            st.push(ans[i].second);
            len--;
        }
    }
    while(st.size()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}