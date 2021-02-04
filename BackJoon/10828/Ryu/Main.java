import java.util.Scanner;

class stk{
	private int size;
	private int[] arr;
	
	public stk() {
		arr = new int[10000];
		size = 0;
	}
	public void push(int temp) {
		if(temp >= 1 || temp <= 100000) {
			arr[size] = temp;
			size++;
		}
	}
	public int pop() {
		if(size == 0) {
			return -1;
		}
		else {
			return arr[--size];
		}
	}
	public int size() {
		return size;
	}
	public int empty() {
		if(size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	public int top() {
		if(size == 0) {
			return -1;
		}
		else {
			return arr[size-1];
		}
	}
}

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a,c;
		String b;
		Scanner input = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		
		a = input.nextInt();
		stk s1 = new stk();
		
		for(int i = 0; i<a; i++) {
			
			b = input.next();
			
			switch(b) {
			
				case"push":
					c = input.nextInt();
					s1.push(c);
					break;
				case"pop":
					sb.append(s1.pop()).append('\n');
					break;
				case"size":
					sb.append(s1.size()).append('\n');
					break;
				case"empty":
					sb.append(s1.empty()).append('\n');
					break;
				case"top":
					sb.append(s1.top()).append('\n');
					break;
			}
		}
		System.out.println(sb);
	}
}
