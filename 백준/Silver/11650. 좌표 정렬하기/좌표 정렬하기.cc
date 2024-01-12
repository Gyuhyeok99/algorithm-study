#include <iostream>
#include <algorithm>
using namespace std;

struct coordinate{
   int x;
   int y;
};

bool cmp(const coordinate& a, const coordinate& b) {
    if(a.x == b.x) {
        return a.y < b.y;
    }
    else {
        return a.x < b.x;
    }
}
int main() {
    int n;
    cin >> n;
    coordinate arr[100004];
    for(int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << arr[i].x << ' ' << arr[i].y << '\n';
    }

    return 0;
}
