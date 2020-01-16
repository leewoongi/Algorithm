package backjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int number[] = new int[100001];
		int sum [] = new int[1000001];	
		
		for(int i= 0; i<number.length; i++) {
			number[i] = 0;
		}
		
		st = new StringTokenizer(br.readLine());
		
		for(int i = 1; i <=N; i ++) {						
			number[i] = Integer.parseInt(st.nextToken());
			sum[i] = sum[i-1] + number[i];
		}
		
		for(int i = 1; i <=M; i++) {
			st = new StringTokenizer(br.readLine());
			
			int number1 = Integer.parseInt(st.nextToken());
			int number2 = Integer.parseInt(st.nextToken());
						
			bw.write(sum[number2] - sum[number1 -1] + "\n");
			bw.flush();
			
		}
		br.close();
		bw.close();
	}	
}
