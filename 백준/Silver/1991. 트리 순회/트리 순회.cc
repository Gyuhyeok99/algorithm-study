#include <iostream>
using namespace std;
pair<char, char> arr[26];
int n;
void preorder(char x) {
    if(x != '.') {
        cout << x;
        preorder(arr[x-'A'].first);
        preorder(arr[x-'A'].second);
    }
}

void inorder(char x) {
    if(x != '.') {
        inorder(arr[x-'A'].first);
        cout << x;
        inorder(arr[x-'A'].second);
    }
}
void postorder(char x) {
    if(x != '.') {
        postorder(arr[x-'A'].first);
        postorder(arr[x-'A'].second);
        cout << x;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        char parent, _left, _right;
        cin >> parent >> _left >> _right;
        arr[(parent - 'A')].first = _left;
        arr[(parent - 'A')].second = _right;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}
