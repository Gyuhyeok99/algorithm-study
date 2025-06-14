import java.util.*;

public class Main {

    private static int n, ret;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        while(n > 0) {
            n--;
            Stack<Character> st = new Stack<>();
            String s = sc.next();
            char[] ch = s.toCharArray();
            boolean flag = true;
            for(char c : ch) {
                if (st.isEmpty() || st.peek() != c) {
                    st.push(c);
                } else {
                    st.pop();
                }
            }
            if(st.empty()) {
                ret++;
            }
        }
        System.out.println(ret);
    }
}
