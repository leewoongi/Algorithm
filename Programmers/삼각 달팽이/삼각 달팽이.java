package com.company;

import java.util.*;

class Solution {
    public int[] solution(int n) {
        int[] answer = {};
        int[][] arr = new int[n][n];
        int[] dx = {1,0,-1};
        int[] dy = {0,1,0};
        int count = 0, number=1;
        int x=-1, y=0, left=0;

        for(int i=n; i>0; i--){
            int val = count % 3;

            for(int j=0; j<i; j++) {
                switch (val) {
                    case 0:
                        x = x + dx[val];
                        arr[x][left] = number;
                        break;
                    case 1:
                        y = y + dy[val];
                        arr[x][y] = number;
                        break;
                    case 2:
                        x = x + dx[val];
                        arr[x][y] = number;
                        break;
                }

                number++;
            }

            if(val == 0) {
                left++;
            }
            else if(val == 2){
                y=left;
            }

            count++;

        }

        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] != 0){
                    list.add(arr[i][j]);
                }
            }
        }

        answer = new int[list.size()];
        for(int i=0; i<list.size(); i++){
            answer[i] = list.get((i));
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {

        int n = 5;

        Solution solution = new Solution();
        System.out.println(solution.solution(n));
    }
}