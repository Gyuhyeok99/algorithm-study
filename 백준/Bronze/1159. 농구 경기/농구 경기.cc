#include <iostream>
#include <vector>
using namespace std;

int n;
string s;
int arr[26];
vector<char> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        arr[s[0] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(arr[i] >= 5) {
            v.push_back(i + 'a');
        }
    }
    if(v.size()) {
        for(char c : v) {
            cout << c;
        }
    }
    else {
        cout << "PREDAJA" << '\n';
    }
    return 0;
}