import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int dp[] = new int[10000];
		dp[1] = 1;
		dp[2] = 3;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int a = Integer.parseInt(in.readLine());
		for(int i = 3; i<=a; i++) {
			dp[i] = (dp[i-1] + (dp[i-2]*2))%10007;
		}
		System.out.print(dp[a]);
	}
}
