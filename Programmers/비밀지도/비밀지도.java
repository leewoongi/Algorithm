package com.company;

import java.util.*;

class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        char[][] ch = new char[n][n];

        for(char[] c : ch){
            Arrays.fill(c,' ');
        }

        for(int i=0; i<n; i++){
            int cnt = n-1;
            while(arr1[i] > 0 || arr2[i] > 0){
                if(arr1[i] % 2 == 1 || arr2[i] % 2 == 1 ){
                    ch[i][cnt] = '#';
                }

                arr1[i] /= 2;
                arr2[i] /= 2;
                cnt--;
            }
        }

        for(int i=0; i<n; i++){
            answer[i] = "";
            for(int j=0; j<n; j++){
                answer[i] += ch[i][j];
            }
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int n = 5;
        int[] arr1 = {9, 20, 28, 18, 11};
        int[] arr2 = {30, 1, 21, 17, 28};
        Solution solution = new Solution();
        System.out.println((solution.solution(n,arr1,arr2)));
    }
}
