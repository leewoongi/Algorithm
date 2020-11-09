package com.company;

import java.util.Arrays;

class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        int array[] = d;
        int money = budget;
        Arrays.sort(d);

        for(int i : d){
            if(money < 0){
                answer--;
                break;
            }
            else if(money > 0){
                if(money >= i){
                    money -= i;
                    answer++;
                }
            }
            else {
                break;
            }

        }
        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int[] d = {2};
        int budget = 1;

        Solution solution = new Solution();
        System.out.println(solution.solution(d,budget));
    }
}
