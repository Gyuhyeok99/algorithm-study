#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> score;
pair<char, char> type[] = {
    {'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}
};

map<int, int> cal = {
    {1, 3}, {2, 2}, {3, 1}, {4, 0}, {5, -1}, {6, -2}, {7, -3}
};
string solution(vector<string> survey, vector<int> choices) {
    string answer = "XXXX";
    for(int i = 0; i < survey.size(); i++) {
        score[survey[i][0]] += cal[choices[i]];
    }
    for(int i = 0; i < 4; i++) {
        if(score[type[i].first] >= score[type[i].second]) {
            answer[i] = type[i].first;
        }
        else {
            answer[i] = type[i].second;
        }
    }
    return answer;
}