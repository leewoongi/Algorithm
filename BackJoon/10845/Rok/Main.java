import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] q;
    static int front,rear;
    static int SIZE;
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        SIZE = N;
        q = new int[SIZE];
        front = 0; rear = 0;
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<SIZE; i++) {
            st = new StringTokenizer(br.readLine());
            switch (st.nextToken()) {
                case "push":
                    push(Integer.parseInt(st.nextToken()));
                    break;
                case "pop":
                    sb.append(pop()).append("\n");
                    break;
                case "size":
                    sb.append(getSize()).append("\n");
                    break;
                case "empty":
                    sb.append(isEmpty()).append("\n");
                    break;
                case "front":
                    sb.append(getFront()).append("\n");
                    break;
                case "back":
                    sb.append(getRear()).append("\n");
                    break;
            }
        }
        System.out.print(sb);
    }
    static void push(int X){
        if(rear<SIZE){
            q[rear++] = X;
        }
    }
    static int pop(){
        if (rear-front == 0){
            return -1;
        }
        return q[front++];
    }
    static int getSize(){
        return rear-front;
    }
    static int isEmpty(){
        if(rear-front == 0){
            return 1;
        }
        return 0;
    }
    static int getFront(){
        if(rear-front == 0){
            return -1;
        }
        return q[front];
    }
    static int getRear(){
        if(rear-front == 0){
            return -1;
        }
        return q[rear-1];
    }
}
