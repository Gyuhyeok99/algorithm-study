#include <string>
#include <vector>
#include <queue>

using namespace std;
int inde[1000004];
int outde[1000004];
vector<int> adj[1000004];
int root;

int findRoot() {
    for(int i = 0; i < 1000004; i++) {
        if(inde[i] == 0 && outde[i] >= 2) {
            return i;
        }
    }
    return -1;
}

int bfs(int here) {
    queue<int> q;
    if(adj[here].size() != 1) {
        if(adj[here].size() == 0) {
            return 2;
        }
        else {
            return 3;
        }
    }
    q.push(adj[here][0]);
    while(q.size()) {
        int there = q.front();
        q.pop();
        if(adj[there].size() != 1) {
            if(adj[there].size() == 0) {
                return 2;
            }
            else {
                return 3;
            }
        }
        if(here == there) {
            return 1;
        }
        q.push(adj[there][0]);
    }
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = {0, 0, 0, 0};
    // 그래프 입력
    for(int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        inde[edges[i][1]]++;
        outde[edges[i][0]]++;
    }
    
    // 루트 찾기
    root = findRoot();
    answer[0] = root;
    
    // 그래프 찾기
    for(int i = 0; i < adj[root].size(); i++) {
        int idx = bfs(adj[root][i]);
        answer[idx]++;
    }
    return answer;
}