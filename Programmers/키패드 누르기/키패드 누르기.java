package com.company;

import java.util.*;

class Solution {
    String answer = "";
    Queue<Point> q = new LinkedList<Point>();
    final int RIGHT = 2;
    final int LEFT = 3;
    int[][] phone = {{1,2,3},{4,5,6},{7,8,9},{10,0,10}};
    int[][] location = {{0,0,0},{0,0,0},{0,0,0},{LEFT,0,RIGHT}};
    int[][] visit = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    int[] dx = {-1,0,1,0};
    int[] dy = {0,1,0,-1};
    int rd=99;
    int ld=99;
    int x_click;
    int y_click;

    class Point{
        private int x;
        private int y;
        private int d;
        public Point(int x, int y, int d){
            this.x=x;
            this.y=y;
            this.d=d;
        }
    }

    public void init(){
        for(int i=0; i< visit.length; i++){
            for(int j=0; j<visit[0].length; j++){
                visit[i][j] = 0;
            }
        }
    }

    public String solution(int[] numbers, String hand) {

        for(int i =0; i<numbers.length; i++){
            rd=99;
            ld=99;
            init();

            if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
                for(int x=0; x<location.length; x++){
                    for(int y=0; y<location[0].length; y++){
                        if(location[x][y] == LEFT){
                            location[x][y] = 0;
                        }
                        if(phone[x][y] == numbers[i]){
                            location[x][y] = LEFT;
                        }
                    }
                }
                answer += "L";
            }

            if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
                for(int x=0; x<location.length; x++){
                    for(int y=0; y<location[0].length; y++){
                        if(location[x][y] == RIGHT){
                            location[x][y] = 0;
                        }
                        if(phone[x][y] == numbers[i]){
                            location[x][y] = RIGHT;
                        }
                    }
                }
                answer += "R";
            }

            if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0){
                for(int x=0; x<location.length; x++){
                    for(int y=0; y<location[0].length; y++){
                        if(phone[x][y] == numbers[i]){
                            if(location[x][y]==LEFT){
                                answer+="L";
                                break;
                            }
                            else if(location[x][y]==RIGHT){
                                answer+="R";
                                break;
                            }
                            location[x][y] = 1;
                            x_click = x;
                            y_click = y;
                            q.add(new Point(x,y,0));
                        }
                    }
                }

                if(!q.isEmpty()){
                    bfs(q);

                    if(ld>rd){
                        answer += "R";
                        for(int x=0; x<location.length; x++) {
                            for (int y = 0; y < location[0].length; y++) {
                                if(location[x][y] == RIGHT){
                                    location[x][y] = 0;
                                }
                            }
                        }
                        location[x_click][y_click] = RIGHT;
                    }
                    else if(ld<rd){
                        answer += "L";
                        for(int x=0; x<location.length; x++) {
                            for (int y = 0; y < location[0].length; y++) {
                                if(location[x][y] == LEFT){
                                    location[x][y] = 0;
                                }
                            }
                        }
                        location[x_click][y_click] = LEFT;
                    }
                    else{
                        if(hand.equals("right")){
                            answer += "R";
                            for(int x=0; x<location.length; x++) {
                                for (int y = 0; y < location[0].length; y++) {
                                    if(location[x][y] == RIGHT){
                                        location[x][y] = 0;
                                    }
                                }
                            }
                            location[x_click][y_click] = RIGHT;
                        }
                        else if(hand.equals("left")){
                            answer += 'L';
                            for(int x=0; x<location.length; x++) {
                                for (int y = 0; y < location[0].length; y++) {
                                    if(location[x][y] == LEFT){
                                        location[x][y] = 0;
                                    }
                                }
                            }
                            location[x_click][y_click] = LEFT;
                        }
                    }
                }
            }
        }

        return answer;
    }

    public void bfs(Queue<Point> q){
        while(!q.isEmpty()){
            Point p = q.poll();
            visit[p.x][p.y]=1;
            for(int i=0; i<dx.length; i++){
                int cx = p.x + dx[i];
                int cy = p.y + dy[i];
                int cd = p.d;
                if(cx >= 0 && cx <= 3 && cy >=0 && cy <= 2 && visit[cx][cy] != 1){
                    visit[cx][cy] = 1;
                    if(location[cx][cy]==LEFT){
                        ld = cd;
                    }
                    else if(location[cx][cy] == RIGHT){
                        rd = cd;
                    }
                    q.add(new Point(cx,cy,cd+1));
                }
            }
        }
    }
}

class Main {

    public static void main(String[] args) {
        int[] number = {0,0,0};
        String hand = "right";
        Solution solution = new Solution();
        System.out.println((solution.solution(number,hand)));
    }
}
