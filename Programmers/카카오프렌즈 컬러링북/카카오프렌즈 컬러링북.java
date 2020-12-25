package com.company;

import java.util.*;

class Node{
    int m;
    int n;
    public Node(int m, int n){
        this.m = m;
        this.n = n;
    }
}

class Solution {
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        int[] answer = new int[2];
        boolean[][] visit = new boolean[m][n];
        Queue<Node> q = new LinkedList<Node>();
        int[] dx = {-1,0,1,0};
        int[] dy = {0,1,0,-1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(picture[i][j] != 0 && !visit[i][j]){
                    q.add(new Node(i,j));
                    visit[i][j] = true;
                    numberOfArea++;
                }

                int area = 0;
                while(!q.isEmpty()){
                    area++;
                    Node node = q.poll();

                    for(int r=0; r<4; r++){
                        int cm = node.m + dx[r];
                        int cn = node.n + dy[r];
                        if(cm >= 0 && cn >= 0
                                && cm < m && cn < n && !visit[cm][cn] &&
                                    picture[cm][cn] == picture[node.m][node.n]){
                            q.add(new Node(cm,cn));
                            visit[cm][cn] = true;
                        }
                    }
                }

                if(maxSizeOfOneArea < area){
                    maxSizeOfOneArea = area;
                }
            }
        }

        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}

class Main {

    public static void main(String[] args) {

        int m = 6;
        int n = 4;
        int[][] picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};

        Solution solution = new Solution();
        System.out.println(solution.solution(m,n,picture));
    }
}
