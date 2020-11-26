package com.company;

import java.util.*;


class Solution {
    public String solution(String s) {
        String answer = "";
        double count = s.length() / 2;
        String str = String.valueOf(count);

        if(s.length()%2 != 0){
            return String.valueOf(s.charAt((int)count));
        }
        else{
            answer =  String.valueOf(s.charAt((int)count-1)) + String.valueOf(s.charAt((int)count));
            return answer;
        }
    }
}

class Main {

    public static void main(String[] args) {
        String s = "abcd";
        Solution solution = new Solution();
        solution.solution(s);
    }
}
