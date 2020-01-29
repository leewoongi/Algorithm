import java.util.Scanner;

public class Main {
	static int n;
	static int k;
	static int coin[];
	static int input[];
	static int now = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		coin = new int[n+1];	
		input = new int[k+1];
		
		for(int i = 1; i<=k; i++) {
			input[i] = 10001;
		}
		
		//동전 입력
		for(int i = 0; i<n; i++) {
			coin[i] = sc.nextInt();			
		}
		
		//동전 저장
		for(int i = 0; i<n; i++) {			
			now = coin[i];
			for(int j= now; j<=k; j++){	
				input[j] = Math.min(input[j-now]+1, input[j]);							
			}
		}
		if(input[k] >= 10001) {
			System.out.println(-1);
		}
		else {
			System.out.println(input[k]);	
		}		
	}
}