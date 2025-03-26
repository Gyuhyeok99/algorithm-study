import java.io.*;
import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> st = new Stack<>();
        
        for(int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            if(a == '(') {
                st.push(a);
            }
            else {
                if(st.size() >= 1) {
                    st.pop();
                }
                else {
                    answer = false;
                    break;
                }
            }
        }
        if(st.size() >= 1) {
            answer = false;
        }
    
        return answer;
    }
}