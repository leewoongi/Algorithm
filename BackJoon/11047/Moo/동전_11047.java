import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		int K = sc.nextInt();

		int min = 0;

		int coin[] = new int[N + 1];

		for (int i = 1; i < N + 1; i++) {
			int input = sc.nextInt();
			coin[i] = input;
		}

		for (int j = N; j > 0; j--) {
			if (K >= coin[j]) {
				min = min + (K / coin[j]);
				K = K % coin[j];
			}
			else if(K == 0) {
				break;
			}
						
		}
		System.out.println(min);
		

	}

}