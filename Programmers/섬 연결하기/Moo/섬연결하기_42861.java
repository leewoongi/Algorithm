package backjoon;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

class Solution {
	
	static int parent[];
	static int sum = 0;
	
	public static void makeSet(int n) {
		for(int i = 0; i<n; i++) {
			parent[i] = i;
		}
	}
	
	public static int find(int a) {
		if(parent[a] == a) {
			return a;
		}
		return parent[a] = find(parent[a]);
	}
	
	public static void union(int a, int b) {
		int aRoot = find(a);
		int bRoot = find(b);
		
		if(aRoot == bRoot) {
			return;
		}
		
		parent[bRoot] = aRoot;
		
	}
	
	public int solution(int n, int[][] costs) {
		parent = new int[n];
        int answer = 0;
        makeSet(n);
               
        //가중치 오름차순으로 정렬	
        Arrays.sort(costs, new Comparator<int[]>() {

			@Override
			public int compare(int[] x, int[] y) {				
				
				return x[2] - y[2];
			}       	
        }); 
        
        // 정렬된 가중치 값들 순차적으로 탐색
        for(int i = 0; i<costs.length; i++) {
        	
        	// find 함수로 연결이 되있는지 확인
        	if(find(costs[i][0]) == find(costs[i][1])){
        		continue;
        	}
        	else {
        		sum+= costs[i][2];
        		union(costs[i][0],costs[i][1]);
        	}
        }
        
        	// find 함수로 연결이 되있는지 확인
        
        	// 안되어있다면 가중치 더해주고, 연결해주기(Union)
        
        
       /*for (int i = 0; i < costs.length; i++) {
            for(int j = 0; j<costs[i].length; j++) {
            	System.out.print(costs[i][j]);
            }
            System.out.println();
        }*/
        answer= sum;
        return answer;
    }
		
	public static void main(String[] args) {	
		//Solution s = new Solution();
		int [][] costs = {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}};		
		System.out.println(new Solution().solution(4,costs));			
	}
}
