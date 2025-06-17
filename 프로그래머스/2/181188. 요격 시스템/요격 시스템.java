import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 1;
        Arrays.sort(targets, (a, b) -> Integer.compare(a[1], b[1]));
        int cur = targets[0][1];
        for(int i = 1; i < targets.length; i++) {
            if(targets[i][0] >= cur) {
                answer++;
                cur = targets[i][1];
            }
        }
        return answer;
    }
}