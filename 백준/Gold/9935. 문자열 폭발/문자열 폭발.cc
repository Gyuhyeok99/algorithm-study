#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    cin >> d;

    vector<char> st;

    for(char c : s) {
        st.push_back(c);
        if(st.size() >= d.size()) {
            bool flag = true;
            for(int i = 0; i < d.size(); i++) {
                if(st[st.size() - d.size() + i] != d[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(int i = 0; i < d.size(); i++) {
                    st.pop_back();
                }
            }
        }
    }
    if(st.empty()) {
        cout << "FRULA" << '\n';
    }
    else {
        for(char c : st) {
            cout << c;
        }
    }
    return 0;
}