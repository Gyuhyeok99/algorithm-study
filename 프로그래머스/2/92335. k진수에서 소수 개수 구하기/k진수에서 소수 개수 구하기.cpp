#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solve(int n, int k) {
    string p = "";
    
    while(n > 0) {
        int r = n % k;
        p = to_string(r) + p;
        n /= k;
    }
    return p;
}

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

bool check(long long num) {
    if(num <= 1) {
        return false;
    }
    if(num == 2) {
        return true;
    }
    for(long long i = 3; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string p = solve(n, k);
    
    vector<string> v = split(p, "0");
    
    for(string s : v) {
        if(s.empty()) {
            continue;
        }
        if(check(stoll(s))) {
            answer++;
        }
    }
    return answer;
}