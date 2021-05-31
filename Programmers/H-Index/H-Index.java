package com.company;

import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int size = citations.length;
        Arrays.sort(citations);
        int max = citations[size-1];

        for(int i = max; i>=0; i--){
            int count = 0;
            for(int j=size-1; j>=0; j--) {
                if(citations[j] >= i){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count >= i){
                answer = i;
                break;
            }
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int[] citations = {3,0,6,1,5}; //0 1 3 5 6

        Solution solution = new Solution();
        System.out.println(solution.solution(citations));
    }
}