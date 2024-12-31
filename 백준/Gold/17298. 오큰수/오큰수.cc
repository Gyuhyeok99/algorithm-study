#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int a[1000004], b[1000004];
int n;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(b, -1, sizeof(b));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        while(st.size() && a[st.top()] < a[i]) {
            b[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    return 0;
}
