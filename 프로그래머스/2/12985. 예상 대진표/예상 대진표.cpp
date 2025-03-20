#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while(1) {
        if(min(a, b) % 2 == 1 && abs(a - b) == 1) {
            break;
        }
        if(a % 2 != 0) {
            a++;
        }
        if(b % 2 != 0) {
            b++;
        }
        a /= 2; b /= 2;
        answer++;
    }
    return answer;
}