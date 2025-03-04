#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321;
int a[101], visited[101];
int n, k, ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        if(!visited[a[i]]) {
            if(v.size() == n) {
                int last = 0, num = 0;
                for(int x : v) {
                    int idx = INF;
                    for(int j = i + 1; j < k; j++) {
                        if(x == a[j]) {
                            idx = j;
                            break;
                        }
                    }
                    if(last < idx) {
                        last = idx;
                        num = x;
                    }
                }
                visited[num] = 0;
                v.erase(find(v.begin(), v.end(), num));
                ret++;
            }
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }
    cout << ret << '\n';
    return 0;
}