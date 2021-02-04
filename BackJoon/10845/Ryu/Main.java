import java.util.Scanner;

class queue{
	int arr[];
	int back, size, point;
	public queue() {
		arr = new int[10000];
		size = point = 0;
	}
	void push(int input) {
		arr[size++] = input;
	}
	int pop() {
		if(size == 0)
			return -1;
		else
		{
			int temp = arr[0];
			for(int i = 0; i<size-1; i++) {
				arr[i] = arr[i+1];
			}
			size--;
			return temp;
		}
	}
	int size() {
		return size;
	}
	int empty() {
		if(size == 0) 
			return 1;
		else
			return 0;
	}
	int front() {
		if(size == 0)
			return -1;
		else
			return arr[0];
	}
	int back() {
		if(size == 0)
			return -1;
		else
			return arr[size-1];
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
		queue s1 = new queue();
		
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
				case"front":
					sb.append(s1.front()).append('\n');
					break;
				case"back":
					sb.append(s1.back()).append('\n');
					break;
			}
		}
		System.out.println(sb);
	}
}
