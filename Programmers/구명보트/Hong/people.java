package com.company;

import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int size = people.length;
        int left = 0;
        int right = size - 1;
        Arrays.sort(people);

        while(left <= right){
            if(left == right){
                answer++;
                break;
            }

            if(people[left] + people[right] <= limit){
                answer++;
                left++;
                right--;
                continue;
            }
            else{
                answer++;
                right--;
            }
        }
        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int[] people = {50,70,80}; //50 50 70 80
        int limit = 100;

        Solution solution = new Solution();
        System.out.println(solution.solution(people,limit));
    }
}