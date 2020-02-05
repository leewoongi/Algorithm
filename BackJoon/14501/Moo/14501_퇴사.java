import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int T[];
	static int P[];
	static int dp[];
	static int period = 0; //기간
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		T = new int[N+1];
		P = new int[N+1];
		dp = new int[100];
		
		for(int i = 1; i<=N; i++) { //1일부터 N일까지
			st = new StringTokenizer(br.readLine());
			T[i] = Integer.parseInt(st.nextToken()); //시간
			P[i] = Integer.parseInt(st.nextToken()); //금액			
		}
		
		//dp
		for(int i = N; i>=1; i--) {
			period = i + T[i];
			
			//기간을 넘으면 그 전 값 저장
			if(period >N +1) {
				dp[i] = dp[i + 1];
			}
			else {
				dp[i] = Math.max(dp[i+1], dp[period] + P[i]);
			}
		}
		System.out.println(dp[1]);
	}
}