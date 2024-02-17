#include <iostream>
using namespace std;

string s, ret;
int cnt[26];
int flag;
char mid;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'A']++;
    }
    for(int i = 25; i >= 0; i--) {
        if(cnt[i]) {
            if(cnt[i] & 1) {
                flag++;
                mid = i + 'A';
                cnt[i]--;
            }
            if(flag == 2) {
                break;
            }
            for(int j = 0; j < cnt[i]; j += 2) {
                ret = char(i + 'A') + ret;
                ret += char(i + 'A');
            }
        }
    }
    if(flag == 2) {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }
    if(flag == 1) {
        ret.insert(ret.begin() + ret.size() / 2, mid);
    }
    cout << ret << '\n';
    return 0;
}