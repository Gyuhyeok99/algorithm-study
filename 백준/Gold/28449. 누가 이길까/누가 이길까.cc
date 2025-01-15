#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, temp;
long long hi_win, arc_win, draw;
vector<int> hi;
vector<int> arc;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        hi.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        arc.push_back(temp);
    }

    sort(hi.begin(), hi.end());
    sort(arc.begin(), arc.end());


    for(int i = 0; i < n; i++) {
        long long temp1 = lower_bound(arc.begin(), arc.end(), hi[i]) - arc.begin();
        long long temp2 = upper_bound(arc.begin(), arc.end(), hi[i]) - arc.begin();
        long long d = temp2 - temp1;

        hi_win += temp1;
        draw += d;
        arc_win += m - temp2;
    }
    cout << hi_win << ' ' << arc_win << ' ' << draw << '\n';
    return 0;
}
