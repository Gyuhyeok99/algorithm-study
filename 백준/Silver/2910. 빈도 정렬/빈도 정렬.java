import java.util.*;

public class Main {
    static int n, c;
    static int[] a;
    static Map<Integer, Integer> mp1, mp2;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        mp1 = new HashMap<>();
        mp2 = new HashMap<>();
        n = sc.nextInt(); c = sc.nextInt();
        a = new int[n];
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            mp1.put(a[i], mp1.getOrDefault(a[i], 0) + 1);
            if(!mp2.containsKey(a[i])) {
                mp2.put(a[i], i);
            }
        }
        Integer[] arr = Arrays.stream(a).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, (x, y) -> {
            if(mp1.get(x) != mp1.get(y)) {
                return mp1.get(y) - mp1.get(x);
            }
            return mp2.get(x) - mp2.get(y);
        });
        for(int num : arr) {
            System.out.print(num + " ");
        }
    }

}
