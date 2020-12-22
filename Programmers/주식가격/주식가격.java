package com.company;

import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int size = prices.length;
        int[] answer = new int[size];

        for(int i=0; i<size; i++){
            int count=0;
            for(int j=i+1; j<size; j++){
                if(prices[i]>prices[j]){
                    count++;
                    break;
                }
                count++;
            }
            answer[i] = count;
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int prices[] = {1, 2, 3, 2, 3};

        Solution solution = new Solution();
        System.out.println(solution.solution(prices));
    }
}
