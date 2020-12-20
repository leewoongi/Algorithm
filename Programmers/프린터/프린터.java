package com.company;

import java.util.*;

class Info {
    int location;
    int priority;

    public Info(int location, int priority){
        this.location = location;
        this.priority = priority;
    }
}

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        ArrayList<Info> info = new ArrayList<>();

        for(int i=0; i<priorities.length; i++){
            info.add(new Info(i,priorities[i]));
        }

        while(!info.isEmpty()) {
            int size = info.size();
            boolean check = false;

            for(int i=1; i<size; i++) {
                if(info.get(0).priority < info.get(i).priority){
                    info.add(info.get(0));
                    info.remove(0);
                    check = true;
                    break;
                }
            }
            if(!check){
                if(location == info.get(0).location){
                    break;
                }
                else{
                    answer++;
                    info.remove(0);
                }
            }
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int[] priorities = {2, 1, 3, 2};
        int location = 2;

        Solution solution = new Solution();
        System.out.println(solution.solution(priorities,location));
    }
}
