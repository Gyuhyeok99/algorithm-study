import java.util.*;

public class Main {

    static int t;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while(t > 0) {
            t--;
            Stack<Character> st = new Stack<>();
            String parenthesis = sc.next();
            boolean flag = true;
            for(int i = 0; i < parenthesis.length(); i++) {
                if(parenthesis.charAt(i) == '(') {
                    st.push(parenthesis.charAt(i));
                }
                else {
                    if(!st.isEmpty() && st.peek() == '(') {
                        st.pop();
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if(!st.isEmpty()) {
                flag = false;
            }
            if(flag) {
                System.out.println("YES");
            }
            else {
                System.out.println("NO");
            }
        }
    }
}
