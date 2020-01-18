package backjoon;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node{
	int x;
	int y;
	Node(){
		
	}
	Node(int x, int y){
		this.x = x;
		this.y = y;
	}
}
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Node node = new Node();
		
		int array[][] = new int[1003][1003];
		boolean visit[][] = new boolean[1003][1003];
		int dx[] = new int [] {-1, 0, 1, 0};
		int dy[] = new int [] {0, 1, 0, -1};
		int result = 0;
		
		int M = sc.nextInt();
		int N = sc.nextInt();
		
		Queue<Node> queue = new LinkedList<Node>(); 
		
		for(int i = 0; i<N; i++) {
			
			for(int j = 0; j<M; j++) {
				array[i][j] = sc.nextInt();
				visit[i][j] = false;
				if(array[i][j] == 1) {
					queue.add(new Node(i,j));
					
				}			
			}
		}
		
		while(!queue.isEmpty()) {
			Node n = queue.remove();
					
			for(int i= 0; i<4; i++) {
				int a = n.x + dx[i];
				int b = n.y + dy[i];				
				if(a>=0 && a<N && b>=0 && b<M) {
					if( array[a][b] ==0 ) {
						queue.add(new Node(a,b));
						array[a][b] = array[n.x][n.y]+1;	//현재 일수 +1																
					}					
				}
			}						
		}
		
			/*for(int i = 0; i < N; i++) {
	            for (int j = 0; j < M; j++) {
	                System.out.print(array[i][j] + " ");
	            }
	            System.out.println();
			}*/

		int maxday = 0;
		
		for(int i = 0; i<N; i++) {
			for(int j= 0; j<M; j++) {
				if(array[i][j] == 0) {
					System.out.println(-1);
					return;
				}
				else {
					maxday = Math.max(maxday,array[i][j]);
				}
			}		
		}
		System.out.println(maxday -1);
	}
}
