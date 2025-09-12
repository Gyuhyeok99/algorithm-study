#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, string> mp;
vector<pair<string, string>> ans;
vector<string> split(string str, string del) {
    vector<string> result;
    auto start = 0;
    auto end = str.find(del);
    while(end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + del.size();
        end = str.find(del, start);
    }
    result.push_back(str.substr(start));
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(string r : record) {
        vector<string> v = split(r, " ");
        string act = v[0];
        if(act == "Enter") {
            string id = v[1];
            string nickname = v[2];
            mp[id] = nickname;
            ans.push_back({"Enter", id});
        }
        else if(act == "Leave") {
            string id = v[1];
            ans.push_back({"Leave", id});
        }
        else if(act == "Change") {
            string id = v[1];
            string nickname = v[2];
            mp[id] = nickname;
        }
    }
    
    for(auto it : ans) {
        string ret = mp[it.second] + "님이 ";
        if(it.first == "Enter") {
            ret += "들어왔습니다.";
        }
        else {
            ret += "나갔습니다.";
        }
        answer.push_back(ret);
    }
    return answer;
}