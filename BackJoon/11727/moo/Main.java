package backjoon;

import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int Tile[] = new int[1001];
		Tile[1] = 1;
		Tile[2] = 3;	
		int i;
		if(n == 1) {		
			System.out.println(Tile[1]);
		}
		else if(n == 2) {		
			System.out.println(Tile[2]);						
		}
		
		else {
			for(i = 3; i<=n; i++) {						
				Tile[i] =(Tile[i-1] + Tile[i-2] + Tile[i-2]) % 10007;
			}
			System.out.println(Tile[i-1]);
		}
		
	}				
}

