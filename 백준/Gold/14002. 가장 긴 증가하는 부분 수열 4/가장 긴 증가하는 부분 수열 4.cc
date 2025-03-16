#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int n, lis[1001], num, len;
vector<pair<int, int>> v;
stack<int> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int pos = lowerPos - lis;
        if(*lowerPos == 0) {
            len++;
        }
        *lowerPos = num;
        v.push_back({pos, num});
    }

    cout << len << '\n';
    for(int i = n - 1; i >= 0; i--) {
        if(v[i].first == len - 1) {
            st.push(v[i].second);
            len--;
        }
    }
    while(st.size()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}