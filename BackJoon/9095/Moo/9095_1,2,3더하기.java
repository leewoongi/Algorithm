package backjoon;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int j;
		int array[] = new int [11];
		
		array [0] = 0;
		array [1] = 1;
		array [2] = 2;
		array [3] = 4;
		for(int i=0;i<n;i++) {
			int count = sc.nextInt();
			if(n == 0) {
				System.out.println(array[0]);			
			}
			else if(count == 1) {
				System.out.println(array[1]);		
			}
			else if(count == 2) {
				System.out.println(array[2]);		
			}
			else if(count == 3) {
				System.out.println(array[3]);			
			}
			else {
				for(j=4; j<=count; j++) {
					array[j] = array[j-3] + array[j-2] + array[j-1];
				}
				System.out.println(array[j-1]);
			}
		}
	}	
}