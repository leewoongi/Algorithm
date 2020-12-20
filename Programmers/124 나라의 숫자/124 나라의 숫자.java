package com.company;

import java.util.*;

class Solution {
    public String solution(int n) {
        String answer = "";
        String[] str = {"4","1","2"};

        int val = 0;

        while(n>0){
            val = n%3;
            n /= 3;

            if(val == 0){
                answer = str[val] + answer;
                n--;
            }
            else{
                answer = str[val] + answer;
            }

        }
        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int n = 12;

        Solution solution = new Solution();
        System.out.println(solution.solution(n));
    }
}
