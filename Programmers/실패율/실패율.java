package com.company;

import java.util.*;


class Info implements Comparable<Info>{
    int number;
    double per;

    public Info(int number, double per){
        this.number = number;
        this.per = per;
    }

    public int getNumber() {
        return number;
    }

    public double getPer() {
        return per;
    }

    @Override
    public int compareTo(Info o) {
        if(this.per > o.getPer())
            return  -1;
        else if(this.per < o.getPer()){
            return 1;
        }
        return 0;
    }

}

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        ArrayList<Info> info = new ArrayList<>();

        for(int i=1; i<=N; i++){
            double per=0;
            double total=0;
            double fail=0;
            for(int j=0; j<stages.length; j++){
                if(stages[j] >= i){
                    total++;
                }
                if(stages[j] == i){
                    fail++;
                }
            }
            per = fail / total;
            info.add(new Info(i, per));
        }

        Collections.sort(info);

        for(int i=0; i<N; i++){
            answer[i] = info.get(i).number;
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        int N = 5;
        int[] stages = {2, 1, 2, 6, 2, 4, 3, 3};

        Solution solution = new Solution();
        solution.solution(N,stages);
    }
}
