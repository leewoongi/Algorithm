package com.company;

import java.util.*;


class Solution {
    public int[] solution(int[] numbers) {
        int[] answer;
        int size = numbers.length;
        TreeSet<Integer> tr = new TreeSet<>();

        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                tr.add(numbers[i] + numbers[j]);
            }
        }
        answer = new int[tr.size()];
        Iterator iter = tr.iterator();
        int count=0;
        while(iter.hasNext()){
            answer[count] = (int) iter.next();
            count++;
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int []arr = {2,1,3,4,1};
        Solution solution = new Solution();
        solution.solution(arr);
    }
}
