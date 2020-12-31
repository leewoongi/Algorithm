package com.company;

import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        int[] list = new int[n+1];

        for(int i=0; i<=n; i++){
            list[i] = i;
        }

        for(int i=2; i<=n; i++){
            if(list[i] == 0){
                continue;
            }

            answer++;
            for(int j=i; j<=n; j=j+i){
                list[j] = 0;
            }
        }
        return answer;
    }
}
class Main {

    public static void main(String[] args) {

        int n = 10;

        Solution solution = new Solution();
        System.out.println(solution.solution(n));
    }
}
