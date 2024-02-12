#include <iostream>
#include <string.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    string ret;
    int arr[26];
    int flag = 0;
    char mid;
    memset(arr, 0, sizeof(arr));
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        arr[s[i] - 'A']++;
    }

    for(int i = 25; i >= 0; i--) {
        if(arr[i]) {
            if(arr[i] & 1) {
                mid = i + 'A';
                flag++;
                arr[i]--;
            }
            if(flag == 2) {
                break;
            }
            for(int j = 0; j < arr[i]; j +=2) {
                ret = (char)(i + 'A') + ret;
                ret += char(i + 'A');
            }
        }
    }

    if(flag == 2) {
        cout <<  "I'm Sorry Hansoo";
        return 0;
    }
    else if(flag == 1) {
        ret.insert(ret.begin() + ret.size()/ 2, mid);
    }
    cout << ret << '\n';
}