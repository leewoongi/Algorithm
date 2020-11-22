package com.company;

import java.util.*;


class Solution {
    public int[] solution(int[] answers) {
        int[][] student = {{1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
                {2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
        int max=0;
        ArrayList<Integer> list = new ArrayList();
        list.add(3);
        for(int n=0; n<3; n++) {
            int point=0;
            for (int i = 0; i < answers.length; i++) {
                int index = i % student[n].length;

                if (answers[i] == student[n][index]) {
                    point++;
                }
            }

            if(point > max){
                max = point;
                list.clear();
                list.add(n+1);
            }
            else if(point == max){
                list.add(n+1);
            }
        }

        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++){
            answer[i] = list.get(i);
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {

        int[] ans = {7, 7, 7, 7, 7, 7, 7, 7, 7, 5};

        Solution solution = new Solution();
        solution.solution(ans);
    }
}
