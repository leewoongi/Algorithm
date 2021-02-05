package com.company;

import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        int size = number.length();
        int index = 0;
        int start = 0;
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<size-k; i++){
            char maxNumber = number.charAt(start);
            index = start;

            for(int j=start; j<=k+i; j++){
                if(maxNumber < number.charAt(j)){
                    maxNumber = number.charAt(j);
                    index = j;
                }
            }
            start = index + 1;
            sb.append(maxNumber);
        }

        return answer = sb.toString();
    }
}

class Main {

    public static void main(String[] args) {

        String number = "4177252841";
        int k = 4;

        Solution solution = new Solution();
        System.out.println(solution.solution(number,k));
    }
}