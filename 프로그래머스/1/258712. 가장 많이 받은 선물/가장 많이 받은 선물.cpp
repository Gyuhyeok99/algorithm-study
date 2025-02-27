#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int arr1[51][51];
int arr2[51];
int arr3[51];

map<string, int> mp;
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    for(int i = 0; i < friends.size(); i++) {
        mp[friends[i]] = i;
    }
    
    
    for(int i = 0; i < gifts.size(); i++) {
        int split = gifts[i].find(' ');
        string from = gifts[i].substr(0, gifts[i].find(' '));
        string to = gifts[i].substr(split + 1);
        arr1[mp[from]][mp[to]]++;
        arr2[mp[from]]++;
        arr2[mp[to]]--;
    }
    
    for(int i = 0; i < friends.size(); i++) {
        for(int j = 0; j < i; j++) {
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
    for(int i = 0; i < friends.size(); i++) {
        answer = max(answer, arr3[i]);
    }
    return answer;
}