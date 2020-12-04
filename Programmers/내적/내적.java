package com.company;

import java.util.*;


class Solution {
    public int solution(int[] a, int[] b) {
        int answer = 0;
        int size = a.length;

        for(int i = 0; i < size; i++){
            answer += a[i] * b[i];
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int[] a = {1,2,3,4};
        int[] b = {-3,-1,0,2};
        Solution solution = new Solution();
        solution.solution(a,b);
    }
}
