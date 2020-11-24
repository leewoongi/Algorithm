package com.company;

import java.util.*;


class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        ArrayList<Integer> list = new ArrayList<Integer>();
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ArrayList<Integer> speed = new ArrayList<Integer>();

        for(int i : speeds){
            speed.add(i);
        }

        int counter = 0;

        for(int i : progresses){
            list.add(i);
        }

        for(int i =0; i<list.size(); i++){
            if(list.get(i) >= 100){
                list.remove(i);
                speed.remove(i);
                counter++;
                i=-1;
            }
            else{
                break;
            }
        }
        if(counter > 0){
            ans.add(counter);
        }

        while(!list.isEmpty()){
            counter = 0;
            for(int i=0; i<list.size(); i++){
                int val;
                val = list.get(i)+speed.get(i);
                list.set(i,val);
            }

            for(int i=0; i<list.size(); i++){
                if(list.get(i) >= 100){
                    list.remove(i);
                    speed.remove(i);
                    counter++;
                    i=-1;
                }
                else{
                    break;
                }
            }
            if(counter > 0){
                ans.add(counter);
            }
        }

        answer = new int[ans.size()];
        for(int i=0; i<ans.size(); i++){
            answer[i] = ans.get(i);
        }
        return answer;
    }
}

class Main {

    public static void main(String[] args) {

        int[] pro = {40, 93, 30, 55, 60, 65};
        int[] speeds = {60, 1, 30, 5, 10, 7};

        Solution solution = new Solution();
        solution.solution(pro,speeds);
    }
}
