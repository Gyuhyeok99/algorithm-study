#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char d[] = {'d', 'l', 'r', 'u'};
int dy[] = {1, 0, 0, -1};
int dx[] = {0, -1, 1, 0};

int arr[51][51];
vector<char> alpha;
vector<string> result;
bool flag = false;
void dfs(int idx, int n, int m, int y, int x, int r, int c, int k) {
    if(flag) {
        return;
    }
    int remaining_dist = abs(y - r) + abs(x - c);
    if (remaining_dist > (k - idx) || (k - idx - remaining_dist) % 2 != 0) return; // 가지치기

    if(idx == k) {
        if(y != r || x != c) {
            return;
        }
        string s(alpha.begin(), alpha.end());
        result.push_back(s);
        flag = true;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
            continue;
        }
        alpha.push_back(d[i]);
        dfs(idx + 1, n, m, ny, nx, r, c, k);
        alpha.pop_back();
    }
    return;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int min_dist = abs(x - r) + abs(y - c);
    if (min_dist > k || (k - min_dist) % 2 != 0) 
        return "impossible";
    
    dfs(0, n, m, x - 1, y - 1, r - 1, c - 1, k);
    
    answer = result[0]; 
    return answer;
}