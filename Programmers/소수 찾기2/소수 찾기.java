package com.company;

import java.util.*;

class Solution {
    static int answer = 0;
    static HashSet<Integer> set = new HashSet<>();

    public int solution(String numbers) {
        int size = numbers.length();
        int[] arr = new int[size];
        boolean[] check = new boolean[size];

        for (int i = 0; i < size; i++) {
            arr[i] = numbers.charAt(i) - '0';
        }

        for(int i=1; i<=size; i++){
            int[] res = new int[i];
            permutation(size,i,arr,check,res,0);
        }


        return answer;
    }

    public static void permutation(int n, int r, int[] arr, boolean[] check, int[] res, int depth) {
        if (depth == r) {
            String str = "";
            int num;
            int loop = 2;
            for(int i=0; i<r; i++){
                str += String.valueOf(res[i]);
            }
            num = Integer.parseInt(str);

            if(set.add(num)){
                while(loop <= num){
                    if(num==2){
                        answer++;break;
                    }

                    if(num % loop == 0){
                        break;
                    }
                    else{
                        loop++;
                    }

                    if(loop == num) {
                        answer++;
                    }
                }
            }

            return;
        }

        for (int i = 0; i < n; i++) {
            if (!check[i]) {
                check[i] = true;
                res[depth] = arr[i];
                permutation(n, r, arr, check, res, depth + 1);
                check[i] = false;
            }
        }
    }
}

class Main {

    public static void main(String[] args) {
        String numbers = "2";

        Solution solution = new Solution();
        System.out.println(solution.solution(numbers));
    }
}