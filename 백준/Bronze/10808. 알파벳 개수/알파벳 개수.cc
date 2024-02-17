#include <iostream>
using namespace std;

string s;
int arr[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
    }
    for(int a : arr) {
        cout << a << ' ';
    }
    return 0;
}