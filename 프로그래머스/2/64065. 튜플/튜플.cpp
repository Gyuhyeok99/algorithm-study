#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;
vector<string> split(string input, string del) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(del);
    while(end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + del.size();
        end = input.find(del, start);
    }
    result.push_back(input.substr(start));
    return result;
}

vector<int> split2(string input, string del) {
    vector<int> result;
    auto start = 0;
    auto end = input.find(del);
    while(end != string::npos) {
        result.push_back(stoi(input.substr(start, end - start)));
        start = end + del.size();
        end = input.find(del, start);
    }
    result.push_back(stoi(input.substr(start)));
    return result;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vv(100001);
    s = s.substr(1, s.size() - 2);
    vector<string> v = split(s, "},");
    for(string& temp : v) {
        if(temp[0] == '{') {
            temp = temp.substr(1);
        }
        if(temp[temp.size() - 1] == '}') {
            temp = temp.substr(0, temp.size() - 1);
        }
        vector<int> v_tmp = split2(temp, ",");
        vv[v_tmp.size() - 1] = v_tmp;
    }
    for(auto a : vv) {
        if(a.size() == 0) {
            break;
        }
        for(auto b : a) {
            if(mp[b] == 0) {
                mp[b]++;
                answer.push_back(b);
            }
        }
    }
    return answer;
}