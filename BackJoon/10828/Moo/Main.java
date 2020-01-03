package backjoon;

import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<Integer>();
		Scanner sc = new Scanner(System.in);
		
		int n = sc. nextInt();
		
		
		for(int i = 0; i<=n; i++) {
			String command = sc.nextLine();
			String array[] = command.split(" ");
			switch(array[0]) {
			case "push":
				stack.push(Integer.parseInt(array[1]));
				break;
				
			case "pop":
				if(stack.isEmpty()) {
					System.out.println(-1);
				}
				else {
					System.out.println(stack.pop());
				}
				break;
				
			case "size":
				System.out.println(stack.size());
				break;
				
			case "empty":
				if(stack.isEmpty()) {
					System.out.println(1);
				}
				else {
					System.out.println(0);
										
				}
				break;
			
			case "top":
				if(stack.isEmpty()) {
					System.out.println(-1);
				}
				else {					
					System.out.println(stack.peek());
				}
				break;
			}
			
		}
		
		
	}
}

