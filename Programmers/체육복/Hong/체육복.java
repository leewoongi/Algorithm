package com.company;

import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.length;
        int[] check = new int[n+1]; //체육복 갯수

        Arrays.sort(lost);
        Arrays.sort(reserve);

        for(int i=0; i<reserve.length; i++){
            check[reserve[i]] = 2;
        }

        for(int i=0; i<lost.length; i++){
            if(check[lost[i]] == 2){
                check[lost[i]] = 1;
                answer++;
            }
        }

        for(int i = 0; i<lost.length; i++){
            if(check[lost[i]]==1){
                continue;
            }

            if(lost[i]-1 >= 1 && check[lost[i]-1]==2){
                check[lost[i]-1] = 1;
                answer++;
            }
            else if(lost[i] + 1 <= n && check[lost[i]+1]==2){
                check[lost[i]+1] = 1;
                answer++;
            }
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int n = 5;
        int[] lost = {1,2,3};
        int[] reserve = {2,3,4};

        Solution solution = new Solution();
        System.out.println(solution.solution(n,lost,reserve));
    }
}