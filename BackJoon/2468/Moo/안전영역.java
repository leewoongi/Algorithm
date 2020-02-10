package backjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node{
	int x;
	int y;
	
	Node(int x, int y){
		this.x = x;
		this.y = y;
	}
}

public class Main {
	static int N;
	static int map[][];
	static boolean visit[][];
	static int dx[] = {-1, 0, 1, 0};
	static int dy[] = {0, 1, 0, -1};
	static int max_height = 0;
	static int height = 0;
	static int start_x = 0;
	static int start_y = 0;
	static Integer count_array[]; //내림차순 함수 쓰려고 Integer 타입으로 선언
	static int count = 0;
	
	//bfs함수
	public static void bfs(int start_x , int start_y) {
		Queue<Node> q = new LinkedList<Node>();
		q.add(new Node(start_x,start_y));
		
		while(!q.isEmpty()) {
			Node n = q.poll();
			
			for(int i = 0; i<4; i++) {
				int a = n.x + dx[i];
				int b = n.y + dy[i];
				
				if(a>=0 && a<N && b>=0 && b<N) {
					if(visit[a][b] == false && map[a][b]>height) {
						q.add(new Node(a,b));
						visit[a][b] = true;
					}
				}
			}
		}
		count++; //인접한곳 연결이 없으면 영역 1씩 증가			
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		visit = new boolean[N][N];
			
		//높이 정보 입력
		for(int i = 0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				//최고높이 저장
				if(map[i][j]> max_height) {
					max_height = map[i][j];
				}				
			}
		}
		
		count_array = new Integer[max_height+1]; //count값을 담는 배열
		
		//높이 0부터 제일 높은 높이까지 계속 bfs 돌려서 제일 안전지역크기가 많은곳을 찾음
		while(true) {
			if(height >max_height)
				break;
			
			//완전탐색
			for(int i = 0; i<N; i++) {
				for(int j= 0; j<N; j++) {
					//높이보다 큰 곳을 찾아서 거기서 bfs 함수 호출
					if(map[i][j] >height && visit[i][j] == false ) {
						start_x = i;
						start_y = j;
						visit[start_x][start_y] = true;
						bfs(start_x, start_y);
												
					}
				}
			}
			//완전탐색 1번 끝나면 visit 배열 초기화
			for(int k = 0; k<N; k++) {
				for(int l = 0; l<N; l++) {
					visit[k][l] = false;
				}
			}
			
			count_array[height] = count;	//각 높이로 기준했을때 그 높이의 안전최대크기를 저장한다			
			count = 0;	//완전탐색 1번 끝나면 count 초기화
			height++;	//완전탐색 1번 끝나면 높이 올려서 다시 반복
		}
		
		//내림차순 정렬
		Arrays.sort(count_array,Collections.reverseOrder()); //각 높이의 안전최대크기를 내림차순으로 정렬한다(가장큰 걸 찾기위함)
		System.out.println(count_array[0]);	//가장 큰걸 출력			
	}
}
