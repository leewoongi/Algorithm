import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Stack{
  int[] n;
  int top;
  int STACK_SIZE;
  public Stack(int N) {
	  n = new int[N];
	  top = -1;
	  STACK_SIZE = N;
  }
  void push(int X) {
	  if(top >= STACK_SIZE-1) {
		  return;
	  }
	  n[++top] = X;
  }
  void pop() {
	  if(top == -1) {
		  System.out.println(-1);
		  return;
	  }
	  System.out.println(n[top--]); 
  }
  void getSize() {
	  System.out.println(top+1);
  }
  void isEmpty() {
	  if(top == -1) {
		  System.out.println(1);
		  return;
	  }
	  System.out.println(0);
  }
  void getTop() {
	  if(top == -1) {
		  System.out.println(-1);
		  return;
	  }
	  System.out.println(n[top]); 
  }
}
public class Main {
    public static void main(String[] args) throws IOException{
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int input = Integer.parseInt(br.readLine());      
    	StringTokenizer st;
    	String str;
    	Stack stack = new Stack(input);
    	for(int i =0; i< input ; i++) {
    		st = new StringTokenizer(br.readLine());
    		switch(st.nextToken()) {
    		case "push":
    			stack.push(Integer.parseInt(st.nextToken()));
    			break;
    		case "pop":
    			stack.pop();
    			break;
    		case "size":
    			stack.getSize();
    			break;
    		case "empty":
    			stack.isEmpty();
    			break;
    		case "top":
    			stack.getTop();
    			break;
    		} 			
    	}
    	
    }
}