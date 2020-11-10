package com.company;

import java.util.Arrays;

class Solution {
    public long solution(int w, int h) {
        long answer = 1;
        long number;

        if(w>h){
            number = gcd(w,h);
        }
        else{
            number = gcd(h,w);
        }

        answer = (long)w*(long)h-(w+h-number);
        return answer;
    }

    public long gcd(long a, long b){
        if(b == 0){
            return a;
        }
        else{
            return gcd(b,a%b);
        }

    }
}

class Main {

    public static void main(String[] args) {
        int w = 8;
        int h = 12;

        Solution solution = new Solution();
        System.out.println(solution.solution(w,h));
    }
}
