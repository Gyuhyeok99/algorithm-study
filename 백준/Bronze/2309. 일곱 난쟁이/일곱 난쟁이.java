import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[9];
        int sum = 0;
        boolean flag = false;
        int a = 0, b = 0;

        for(int i = 0; i < 9; i++) {
            arr[i] = scanner.nextInt();
            sum += arr[i];
        }
        Arrays.sort(arr);
        for(int i = 0; i < 9; i++) {
            if(flag) {
                break;
            }
            for(int j = i; j < 9; j++) {
                if(i == j) {
                    continue;
                }
                if(sum - arr[i] - arr[j] == 100) {
                    a = i;
                    b = j;
                    flag = true;
                    break;
                }
            }
        }
        for(int i = 0; i < 9; i++) {
            if(i == a || i == b) {
                continue;
            }
            System.out.println(arr[i]);
        }
    }
}
