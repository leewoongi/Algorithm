package backjoon;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int n;
	static int m;
	static int first, second;
	static boolean visit[];
	static int map[][];
	static int dept[];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		first = sc.nextInt();
		second = sc.nextInt();
		m = sc.nextInt();
		map = new int[n + 1][n + 1];
		visit = new boolean[n + 1];
		dept = new int[n + 1];

		// 1촌 관계에 있는 것들을 전부 저장
		for (int i = 0; i < m; i++) {
			int parent = sc.nextInt();
			int child = sc.nextInt();
			map[parent][child] = map[child][parent] = 1;
		}

		int chonsu = bfs();
		if(chonsu == 0) {
			System.out.println(-1);
		}
		else {
			System.out.println(chonsu);
		}		
	}

	public static int bfs() {
		Queue<Integer> q = new LinkedList<>();
		q.add(first);
		visit[first] = true;
		//dept[first] = 0;
	
		while (!q.isEmpty()) {
			int node = q.remove();

			if (node == second) {
				break;
			}

			/*
			 * 7부터 쭉 돌려서 1촌 관계에 있던게 나오면 그 점을 add하고 방문했다고 표시 그리고 그 점부터 다시 쭉 돌려서 1촌관계에 있던 점들을
			 * 찾아서 3이 나올때까지 반복
			 */
			for (int i = 1; i <= n; i++) {
				if (map[node][i] == 1 && visit[i] == false) {
					q.add(i);
					visit[i] = true;
					dept[i] = dept[node] + 1;
				}
			}
		}
		return dept[second];
	}
}
