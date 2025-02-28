#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, string> m = {
    {"zero", "0"}, {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}
    , {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"},
};

int solution(string s) {
    int answer = 0;
    string result = "";
    for(int i = 0; i < s.size(); i++) {
        if(!isdigit(s[i])) {
            if(m.find(s.substr(i, 3)) != m.end()) {
                result = result + m[s.substr(i, 3)];
                i += 2;
            }
            else if(m.find(s.substr(i, 4)) != m.end()) {
                result = result + m[s.substr(i, 4)];
                i += 3;
            }
            else if(m.find(s.substr(i, 5)) != m.end()) {
                result = result + m[s.substr(i, 5)];
                i += 4;
            }
        }
        else {
            result = result + s[i];
        }
    }
    answer = stoi(result);
    return answer;
}