#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int ret;
int arr1[51][51];
int arr2[51];
int arr3[51];
map<string, int> mp;
pair<string, string> split(string s) {
    auto del = s.find(' ');
    return {s.substr(0, del), s.substr(del + 1)};
}
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(int i = 1; i <= friends.size(); i++) {
        mp[friends[i - 1]] = i; 
    }
    
    for(int i = 0; i < gifts.size(); i++) {
        auto p = split(gifts[i]);
        int a = mp[p.first];
        int b = mp[p.second];
        arr1[a][b]++;
        arr2[a]++;
        arr2[b]--;
    }
    for(int i = 1; i <= friends.size(); i++) {
        for(int j = 1; j <= i; j++) {
            if(i == j) {
                continue;
            }
            if(arr1[i][j] > arr1[j][i]) {
                arr3[i]++;
            }
            else if(arr1[i][j] < arr1[j][i]) {
                arr3[j]++;
            }
            else {
                if(arr2[i] > arr2[j]) {
                    arr3[i]++;
                }
                else if(arr2[i] < arr2[j]) {
                    arr3[j]++;
                }
            }
        }
    }
    for(int i = 1; i <= friends.size(); i++) {
        answer = max(answer, arr3[i]);
    }
    return answer;
}