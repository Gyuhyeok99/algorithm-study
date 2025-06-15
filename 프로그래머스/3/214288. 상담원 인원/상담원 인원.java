import java.util.*;

class Solution {
    private static int INF = 987654321;
    private static List<int[]>[] list;
    private static int[] arr;
    private static int nn, kk;
    
    public int solution(int k, int n, int[][] reqs) {
        int answer = 0;
        list = new ArrayList[k];
        arr = new int[k];
        Arrays.fill(arr, 1);
        nn = n;
        kk = k;
         
        for(int i = 0; i < k; i++) {
            list[i] = new ArrayList<>();
        }
         
        for(int[] req : reqs) {
            int s = req[0];
            int t = req[1];
            int c = req[2];
            int[] temp = new int[]{s, t};
            list[c - 1].add(temp);
        }
        answer = solve(0, 0);
        return answer;
    }
    
    private static int solve(int idx, int cnt) {
        if(cnt == nn - kk) {
            int sum = 0;
            for(int i = 0; i < kk; i++) {
                Queue<int[]> q = new LinkedList<>(list[i]);
                PriorityQueue<Integer> pq = new PriorityQueue<>();
                int remain = arr[i];
                while(!q.isEmpty()) {
                    int[] temp = q.poll();
                    if(remain > 0) {
                        pq.add(temp[0] + temp[1]);
                        remain--;
                    }
                    else {
                        int last = pq.peek();
                        if(last > temp[0]) {
                            sum += last - temp[0];
                            pq.add(last + temp[1]);
                        }
                        else {
                            pq.add(temp[0] + temp[1]);
                        }
                        pq.poll();
                    }
                }
            }
            return sum;
        }
        
        int ret = INF;
        
        if(idx >= kk) {
            return ret;
        }
        
        for(int i = 0; i < nn - kk - cnt + 1; i++) {
            arr[idx] += i;
            ret = Math.min(ret, solve(idx + 1, cnt + i));
            arr[idx] -= i;
        }
        return ret;
    }
}
