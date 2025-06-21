import java.util.*;

class Solution {
    static int[][] d;
    static int n, k, maxCnt;
    static int[] answer;
    public int[] solution(int[][] dice) {
        d = dice;
        n = dice.length;
        k = n / 2;
        answer = new int[k];
        
        combi(-1, new ArrayList<>());
        return answer;
    }
    
    static void combi(int start, List<Integer> selectedA) {
        if(selectedA.size() == k) {
            List<Integer> selectedB = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                if(!selectedA.contains(i)) {
                    selectedB.add(i);
                }
            }
            List<Integer> sumA = new ArrayList<>();
            List<Integer> sumB = new ArrayList<>();
            getSum(0, 0, selectedA, sumA);
            getSum(0, 0, selectedB, sumB);
            
            Collections.sort(sumB);
            int cnt = 0;
            for(int a : sumA) {
                cnt += lowerBound(sumB, a);
            }
            
            if(cnt > maxCnt) {
                maxCnt = cnt;
                for (int i = 0; i < k; i++) {
                    answer[i] = selectedA.get(i) + 1;
                }
            }
            return;
        }
        for(int i = start + 1; i < n; i++) {
            selectedA.add(i);
            combi(i, selectedA);
            selectedA.remove(selectedA.size() - 1);
        }
    }
    
    static void getSum(int idx, int sum, List<Integer> selectedX, List<Integer> sumX) {
        if (idx == selectedX.size()) {
            sumX.add(sum);
            return;
        }
        int diceIdx = selectedX.get(idx);
        for (int i = 0; i < 6; i++) {
            getSum(idx + 1, sum + d[diceIdx][i], selectedX, sumX);
        }
    }
    
    static int lowerBound(List<Integer> list, int target) {
        int left = 0, 
        right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (list.get(mid) < target) {
                left = mid + 1;
            } 
            else {
                right = mid;
            }
        }
        return left;
    }
}