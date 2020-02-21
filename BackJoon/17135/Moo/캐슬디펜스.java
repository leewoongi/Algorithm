import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {
	int x;
	int y;
	int d;

	Node(int x, int y, int d) {
		this.x = x;
		this.y = y;
		this.d = d;
	}
}

public class Main {
	static int N;
	static int M;
	static int D;
	static int start_x = 0;
	static int start_y = 0;
	static int map[][];
	static int change[][];
	static boolean visit[]; // 조합할때 쓰는 배열
	static boolean visited[][]; // bfs 이용할때 체크하는 배열
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	static int count = 0;
	static int result = 0;
	static int n = 0;
	static boolean visited2[][];

	static Queue<Node> q = new LinkedList<Node>();
	static ArrayList<Node> list = new ArrayList<Node>();
	static ArrayList<Node> list2 = new ArrayList<Node>();

	// 백트래킹을 이용한 조합( 궁수 위치 정하기)
	public static void combination(int idx, int cnt) {
		if (cnt == 3) {
			copy(); // 맵 복사
			init_visited(); // visited 초기화
			position(); // 궁수 위치 설정			
			return;
		}
		for (int i = idx; i < M; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				combination(i, cnt + 1);
				visit[i] = false;
			}
		}
	}

	// 맵 복사
	public static void copy() {
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < M; j++) {
				change[i][j] = map[i][j];
			}
		}
	}

	// visited 초기화
	public static void init_visited() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}
	}

	public static boolean map_check() {
		boolean check = false;
		for(int i = 0; i<N;i++) {
			for(int j = 0; j<M;j++) {
				if(change[i][j] == 1) {
					check = true;
					break;
				}
			}
		}
		return check;
	}
	// 궁수 위치 설정
	public static void position() {
			
		while(true){
			boolean flag = false;		
			 flag = map_check();
			 
			 if(flag == false) {
				 break;
			 }
			 
			for (int j = 0; j < M; j++) {

				if (visit[j] == true) {
					change[N][j] = 2; // 궁수의 위치
					visited[N][j] = true;
					q.add(new Node(N, j, 0));
					init_visited();
					bfs();
				}
			}			
						
			// 3명 궁수 1턴 끝나면 1을 0으로 바꿔줌
			for (int i = 0; i < list2.size(); i++) {
				Node begint = list2.get(i);

				if (change[begint.x][begint.y] == 1) {
					change[begint.x][begint.y] = 0;
					count++;
				}
			}
				
			list2.clear();
			result = Math.max(result, count);
			under();		
		}
		
		count = 0;

	}

	// 궁수가 공격하면 적을 내린다
	public static void under() {
		for (int i = N-1; i >=1; i--) {
			for (int j = 0; j < M; j++) {
				change[i][j] = change[i - 1][j];
			}
		}

		// 첫번째 행 초기화
		for (int i = 0; i < 1; i++) {
			for (int j = 0; j < M; j++) {
				change[i][j] = 0;
			}
		}
	}

	// 적들의 우선순위 정렬
	public static void cmp() {
		Collections.sort(list, new Comparator<Node>() {

			@Override
			public int compare(Node p1, Node p2) {
				// 거리가 다르면 거리가 가까운것부터
				if (p1.d != p2.d) {
					return p1.d - p2.d;
				}
				// 거리가 같으면
				else {
					return p1.y - p2.y;
				}
			}
		});
	}

	// position()

	// bfs 탐색
	public static void bfs() {

		while (!q.isEmpty()) {
			Node n = q.poll();
			for (int i = 0; i < 4; i++) {
				int a = n.x + dx[i];
				int b = n.y + dy[i];

				if (a >= 0 && a < N && b >= 0 && b < M) {
					// 탐색을한다.
					if (visited[a][b] == false) {
						q.add(new Node(a, b, n.d + 1));
						visited[a][b] = true;

						// 만약 공격거리 범위내에 적이있으면 list에 담는다.
						if (change[a][b] == 1 && n.d <D) {
							
							list.add(new Node(a, b, n.d + 1));
																											
						}
					}
				}
			}
		}			
		if(list.size() != 0) {
			cmp();
			list2.add(list.get(0));		
			list.clear();
		}	
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		map = new int[N + 1][M];
		change = new int[N + 1][M];
		visit = new boolean[M];
		visited = new boolean[N + 1][M];
		visited2 = new boolean[100][100];

		// 맵 입력
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		combination(0, 0);
		System.out.println(result);

	}
}