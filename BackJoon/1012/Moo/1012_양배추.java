package backjoon;

import java.util.Scanner;
import java.util.Stack;
class NODE{
	int x;
	int y;

	NODE() {

	}
	NODE(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        NODE n = new NODE();

        int dx[] = new int[] {1 , 0 , -1 , 0 };
        int dy[] = new int[] {0 , 1 ,  0 , -1};
        int array[][] = new int[51][51];
        boolean visit[][] = new boolean[51][51];
        int cabbage;
        
        
        int tc;
        int t = sc.nextInt();
      
        for(tc = 1; tc<=t; tc++) {
        	int M = sc.nextInt();
        	int N = sc.nextInt();
        	int K = sc.nextInt();
        	int count = 0;
        	
        	for(int j = 0; j < M; j++) {
        		for(int k = 0; k < N; k++) {
        			array[j][k] = 0;
        			visit[j][k] = false;
        		}
        	}

        	for(int i = 0; i < K; i++) {
        		int x,y;
        		x = sc.nextInt();
        		y = sc.nextInt();
        		       		
        		array[x][y] = 1;
        	}
        	
        	Stack<NODE> st = new Stack<>();
        	
        		
        	for(int i = 0; i<M; i++) {	
        		for(int j = 0; j<N; j++) {
           			
        			if(array[i][j] == 1 && visit[i][j]== false) {
        				count++;
        				st.push(new NODE(i,j));
        				visit[i][j] = true;
        				
        				while(!st.empty()) {
        					
        					n = st.pop();
        					
        					for(int k = 0; k<4; k++) {
        						int a = n.x + dx[k];
        						int b = n.y + dy[k];
        						
        						if(a>=0 && a<M && b>=0 && b<N) {
        							if(visit[a][b] == false && array[a][b]==1) {
        								st.push(new NODE(a,b));
        								visit[a][b] = true;
        							}
        						}
        					}
        				}
        			}	
        		}
        	} 
        	System.out.println(count);        	       	
        }   
        
    }
}