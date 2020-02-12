package programmers;

import java.util.LinkedList;
import java.util.Queue;

class Node{
	int x;
	int y;
	int d;
	
	Node(int x, int y, int d){
		this.x = x;
		this.y = y;
		this.d = d;
	}
}
class Solution {
	static int map[][];;
	static boolean[][] visit;
	static int N;
	static int M;
	static int count =0;
	static int dx[] = {-1, 0, 1, 0};
	static int dy[] = {0, 1, 0, -1};
	static int start_x = 0;
	static int start_y = 0;
	
	public static int bfs() {
		Queue<Node> q = new LinkedList<Node>();
		q.add(new Node(0,0,1));
		visit[0][0] = true;
		
		while(!q.isEmpty()) {
			Node n = q.poll();
			if(n.x == N-1 && n.y == M-1) {
				
				count = n.d;				
			}
			
			
			for(int i = 0; i<4; i++) {
				int a = n.x + dx[i];
				int b = n.y + dy[i];
				
				if(a>=0 && a<N & b>=0 && b<M) {
					if(visit[a][b] == false && map[a][b] == 1) {
						q.add(new Node(a,b,n.d+1));
						visit[a][b] = true;
					}
				}
			}			
		}
		return count;	
	}
	
	public int solution(int[][] maps) {
		int answer = 0;
		
		N = maps.length;
		M = maps[0].length;
		map = new int[N][M];
		visit = new boolean[N][M];
		
		for(int i = 0; i<N; i++) {
			for(int j = 0; j<M; j++) {
				map[i][j] = maps[i][j];				
			}
		}
		answer = bfs();
		
		if(answer == 0)
			return -1;
		
		return answer;
			
	}
	
	public static void main(String[] args) {
		Solution s = new Solution();
		int maps[][] = {{1,0,1,1,1},{1,0,1,0,1},
		                {1,0,1,1,1},{1,1,1,0,0},
		                {0,0,0,0,1}};
		System.out.println(s.solution(maps));
	}
}

