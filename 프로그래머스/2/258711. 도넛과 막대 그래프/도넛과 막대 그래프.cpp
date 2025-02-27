#include <string>
#include <vector>
#include <queue>

using namespace std;
int inde[1000005];  
int outde[1000005]; 
int root = -1;
vector<int> v[1000005];
int findRoot() {
    for(int i = 0; i < 1000005; i++) {
        if(inde[i] == 0 && outde[i] >= 2) {
            return i;
        }
    }
    return -1;
}

int bfs(int here) {
    queue<int> q;
    
    if(v[here].size() != 1) {
        if(v[here].size() == 0) {
            return 2;
        }
        else {
            return 3;
        }
    }
    q.push(v[here][0]);
    while(q.size()) {
        int there = q.front();
        q.pop();
        if(v[there].size() != 1) {
            if(v[there].size() == 0) {
                return 2;
            }
            else {
                return 3;
            }
        }
        if(there == here) {
            return 1;
        }
        q.push(v[there][0]);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = {0, 0, 0, 0};
    for(int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
        inde[edges[i][1]]++;
        outde[edges[i][0]]++;
    }
    root = findRoot();
    answer[0] = root;
    
    for(int i = 0; i < v[root].size(); i++) {
        int idx = bfs(v[root][i]);
        answer[idx]++;
    }
    return answer;
}