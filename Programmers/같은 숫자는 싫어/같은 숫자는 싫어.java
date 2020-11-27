package com.company;

import java.util.*;


class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        int size = arr.length;
        int number = arr[0];
        ArrayList<Integer> list = new ArrayList<>();
        list.add(arr[0]);

        for(int i : arr){
            if(i != number){
                list.add(i);
                number = i;
            }
        }

        answer = new int[list.size()];
        for(int i = 0 ; i<list.size(); i++){
            answer[i] = list.get(i);
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int []arr = {1,1,3,3,0,1,1};
        Solution solution = new Solution();
        solution.solution(arr);
    }
}
