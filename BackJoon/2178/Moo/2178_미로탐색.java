import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class NODE{
	int x;
	int y;
	
	NODE(){
		
	}
	NODE(int x, int y){
		this.x = x;
		this.y = y;
	}
}

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, 1, 0, -1};
		int array[][] = new int[101][101];
		boolean visit[][] = new boolean[101][101];
		int count = 1;
		int sum_count =1;
				
		NODE start = new NODE();
		NODE end = new NODE();
		
		int N = sc.nextInt();
		int M = sc.nextInt();
			
		for(int i = 0; i<N; i++) {
			String input = sc.next();
			String arrayArr[] = input.split("");
			
			for(int j = 0; j<M; j++) {
				array[i][j] = Integer.parseInt(arrayArr[j]);
				visit[i][j] = false;			
			}		
		}
		
		Queue<NODE> queue = new LinkedList<>();
		queue.add(new NODE(0,0));
		visit[0][0] = true;
					
		while(!queue.isEmpty()) {
			NODE n = queue.poll();
			
			if(n.x == N-1 && n.y == M-1) {			
				break;
			}
					
			for(int i = 0; i<4; i++) {
				int a = n.x + dx[i];
				int b = n.y + dy[i];
												
				if(a >=0 && a<N && b>=0 && b<M) {
					if(visit[a][b] == false && array[a][b] == 1) {
						queue.add(new NODE(a,b));
						visit[a][b] = true;
						array[a][b] = array[n.x][n.y] + 1;
						
					}					
				}
			}
		}
		System.out.println(array[N-1][M-1]);
				
	}	
}