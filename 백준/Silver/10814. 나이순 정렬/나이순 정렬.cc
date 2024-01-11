#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct person {
    int idx;
    int age;
    string name;
};

bool cmp(const person& a, const person& b) {
    if(a.age != b.age) {
        return a.age < b.age;
    }
    return a.idx < b.idx;
}
int main() {
    int n;
    cin >> n;
    person arr[100004];
    for(int i = 0; i < n; i++){
        cin >> arr[i].age >> arr[i].name;
        arr[i].idx = i;
    }

    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++) {
        cout << arr[i].age << ' ' << arr[i].name << '\n';
    }

    return 0;
}
