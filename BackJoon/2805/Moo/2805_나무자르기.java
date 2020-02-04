import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;

public class Main {
	static int N;
	static long M;
	static int[] tree;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		// 입력
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		tree = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			tree[i] = Integer.parseInt(st.nextToken());
		}			
		// 오름차순으로 정렬
		Arrays.sort(tree); // 10 15 17 20
		
		long first = 0;
		long last = tree[tree.length-1]; //20
		long result =0;
		long middle = 0;
		long high = 0;
		
		while (first <= last) {
			long sum = 0;		
			long cut = 0;
					
			for(int i = 0; i<N; i++) {
				middle = (first + last) / 2;
				cut = tree[i] - middle;
				if(cut <0) {
					cut = 0;
				}
				sum += cut;
			}
			if (sum >= M) {
				first = middle + 1;
				if(middle > high ) {
					high = middle;
				}
			} 
			else if (sum < M) {
				last = middle -1;
			}
		}
		System.out.println(high);		
		br.close();
		bw.close();
	}
}