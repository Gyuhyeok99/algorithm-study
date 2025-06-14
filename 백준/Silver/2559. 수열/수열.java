import java.util.*;

public class Main {

    private static int n, k, ret = -987654321;
    private static int[] pSum;
    private static int[] num;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        num = new int[n];
        pSum = new int[n + 1];
        for(int i = 0; i < n; i++) {
            num[i] = sc.nextInt();
        }
        for(int i = 1; i <= n; i++) {
            pSum[i] = pSum[i - 1] + num[i - 1];
        }
        for(int i = 0; i <= n - k; i++) {
            ret = Math.max(ret, pSum[i + k] - pSum[i]);
        }
        System.out.println(ret);

    }
}
