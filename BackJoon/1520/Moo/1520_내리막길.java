import java.util.Scanner;
import java.util.Stack;

public class Main {
	static int M;
	static int N;
	static int map[][];
	static int dp[][];

	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	static int count = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		M = sc.nextInt();
		N = sc.nextInt();
		map = new int[M][N];
		dp = new int[M][N];

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = sc.nextInt();
				dp[i][j] = -1;
			}
		}

		int start_x = 0, start_y = 0;
		// int edn_x = M-1, end_y = N-1;

		int result = dfs(start_x, start_y);
		System.out.println(result);
	}

	public static int dfs(int x, int y) {

		if(x == M-1 && y == N-1) {
			return 1;
		}
        dp[x][y] =0;
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a >= 0 && a < M && b >= 0 && b < N) {

				if (map[a][b] < map[x][y]) {
					if(dp[a][b] != -1) {
						dp[x][y] = dp[x][y] + dp[a][b];
						continue;
					}
					dp[x][y] = dp[x][y] + dfs(a,b);
				}

			}
		}
		return dp[x][y];

	}

}
