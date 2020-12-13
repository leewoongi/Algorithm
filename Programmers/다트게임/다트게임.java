package com.company;

import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        String number = "";
        ArrayList<Integer> list = new ArrayList<>();
        int size = dartResult.length();

        for(int i=0; i<size; i++){
            char ch = dartResult.charAt(i);

            if(ch >= '0' && ch <= '9'){
                number += dartResult.charAt(i);
            }
            else if(ch =='S' || ch == 'D' || ch == 'T'){
                if(ch == 'S'){
                    list.add(Integer.valueOf(number));
                    number = "";
                }
                else if(ch == 'D'){
                    list.add(Integer.valueOf(number)*Integer.valueOf(number));
                    number = "";
                }
                else if(ch == 'T'){
                    list.add(Integer.valueOf(number)*Integer.valueOf(number)*Integer.valueOf(number));
                    number = "";
                }
            }
            else if(ch == '#' || ch == '*'){
                int listSize = list.size();

                if(ch == '#'){
                    list.set(listSize-1,(list.get(listSize-1)*-1));
                }
                else if(ch == '*'){
                    list.set(listSize-1,(list.get(listSize-1)*2));
                    if(listSize > 1){
                        list.set(listSize-2,(list.get(listSize-2)*2));
                    }
                }
            }
        }

        for(int i : list){
            answer += i;
        }

        return answer;
    }
}

class Main {

    public static void main(String[] args) {
        String dartResult = "1D2S#10S";
        Solution solution = new Solution();
        System.out.println((solution.solution(dartResult)));
    }
}
