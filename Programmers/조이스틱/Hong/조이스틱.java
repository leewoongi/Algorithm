package com.company;

import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        int size = name.length();
        int index = 0;
        int left = index, right = index;
        StringBuffer res = new StringBuffer();
        StringBuffer init = new StringBuffer();
        int leftIndex=0;
        int rightIndex=0;

        res.append(name);

        for(int i=0; i<size; i++){
            init.append('A');
        }


        while(true) {
            if(right <= left){
                answer += right;
                index = rightIndex;
            }
            else{
                answer += left;
                index = leftIndex;
            }

            char ch = name.charAt(index);
            if(ch != 'A'){
                answer += Math.min(ch - 'A', 'Z' - ch + 1);
                res.replace(index,index+1,"A");
            }

            if(init.toString().equals(res.toString())){
                break;
            }

            leftIndex = index;
            rightIndex = index;
            for(int i=1; i<size; i++){
                if(rightIndex == size - 1){
                    rightIndex = 0;
                }
                else{
                    rightIndex++;
                }

                if(res.charAt(rightIndex)!='A'){
                    right = i;
                    break;
                }
            }

            for(int i=1; i<size; i++){
                if(leftIndex == 0){
                    leftIndex = size - 1;
                }
                else{
                    leftIndex--;
                }

                if(res.charAt(leftIndex)!='A'){
                    left = i;
                    break;
                }
            }
        }
        return answer;
    }
}

class Main {

    public static void main(String[] args) {

        //String name = "JAZ";
        //String name = "JEROEN";
        //String name = "AAAB";

        //9
        String name = "BBBAAAB";

        //11
        //String name = "ABABAAAAABA";

        //String name = "ABAA";

        Solution solution = new Solution();
        System.out.println(solution.solution(name));
    }
}
