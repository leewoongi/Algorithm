package backjoon;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Queue<Integer> queue = new LinkedList<Integer>();
		Scanner sc = new Scanner(System.in);
		
		int n = sc. nextInt();
		
		int pushlast =0;
			
		for(int i = 0; i<=n; i++) {
			String command = sc.nextLine();
			String array[] = command.split(" ");
			switch(array[0]) {
			case "push":
				 pushlast = Integer.parseInt(array[1]);
				 
				 queue.offer(pushlast);
				break;
				
			case "pop":
				if(queue.isEmpty()) {
					System.out.println(-1);
				}
				else {
					System.out.println(queue.poll());
				}
				break;
				
			case "size":
				System.out.println(queue.size());
				break;
				
			case "empty":
				if(queue.isEmpty()) {
					System.out.println(1);
				}
				else {
					System.out.println(0);
										
				}
				break;
			
			case "front":
				if(queue.isEmpty()) {
					System.out.println(-1);
				}
				else {					
					System.out.println(queue.peek());
				}
				break;
				
			case "back":
				if(queue.isEmpty()) {
					System.out.println(-1);
				}
				else {
					System.out.println(pushlast);
				}
								
			}
			
		}
		
		
	}
}

