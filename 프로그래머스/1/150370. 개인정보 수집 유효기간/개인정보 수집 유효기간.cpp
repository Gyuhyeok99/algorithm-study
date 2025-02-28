#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

map<char, int> mp;

int fomatter(string s) {
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));
    return year * 12 * 28 + (month - 1) * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        char grade;
        int month;
        ss >> grade >> month;
        mp[grade] = month;
    }
    
    int total = fomatter(today);
    
    for(int i = 0; i < privacies.size(); i++) {
        int privacie = fomatter(privacies[i]);
        char grade = privacies[i].back();
        privacie += (mp[grade] * 28) - 1;
        if(privacie < total) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}