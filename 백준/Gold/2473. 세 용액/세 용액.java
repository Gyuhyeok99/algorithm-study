import java.util.*;

public class Main {

    private static int n;
    private static long[] arr;
    private static long ret = (long)10e18, a, b, c;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new long[n];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        Arrays.sort(arr);
        for(int i = 0; i < n - 2; i++) {
            int s = i + 1;
            int e = arr.length - 1;
            while(s < e) {
                long temp = arr[i] + arr[s] + arr[e];
                if(Math.abs(temp) < ret) {
                    ret = Math.abs(temp);
                    a = arr[i];
                    b = arr[s];
                    c = arr[e];
                }
                if(temp < 0) {
                    s++;
                }
                else {
                    e--;
                }
            }
        }
        System.out.println(a + " " + b + " " + c + " ");
    }
}
