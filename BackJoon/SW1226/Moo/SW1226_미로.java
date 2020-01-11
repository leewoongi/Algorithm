package backjoon;

import java.util.Scanner;
import java.util.Stack;

public class Solution {

   public static void main(String[] args) {

      Scanner sc = new Scanner(System.in);
      Stack<Integer> stackX = new Stack<Integer>();
      Stack<Integer> stackY = new Stack<Integer>();

      int dx[] = new int[] { -1, 0, 1, 0 };
      int dy[] = new int[] { 0, 1, 0, -1 };
      int array[][] = new int[16][16];
      boolean visit[][] = new boolean[16][16];

      for (int i = 0; i < 10; i++) {
         int t = sc.nextInt();
         
         int result = 0;
         int startX = 1;
         int startY = 1;
         int endX = 15;
         int endY = 15;

         for (int j = 0; j < 16; j++) {
            String input = sc.next();
            String[] inputArr = input.split("");

            for (int k = 0; k < 16; k++) {
               array[j][k] = Integer.parseInt(inputArr[k]);
               visit[j][k] = false;

               if (array[j][k] == 2) {
                  startX = j;
                  startY = k;
               } else if (array[j][k] == 3) {
                  endX = j;
                  endY = k;
               }
            }
         }
         
         stackX.push(startX);
         stackY.push(startY);
         visit[startX][startY] = true;

         while (!stackX.isEmpty() && !stackY.isEmpty()) {

            int x = stackX.peek();
            int y = stackY.peek();
            stackX.pop();
            stackY.pop();

            if (x == endX && y == endY) {
               result = 1;
               break;
            }
            for (int j = 0; j < 4; j++) {
               int a = x + dx[j];
               int b = y + dy[j];

               if (a >= 0 && a < 16 && b >= 0 && b < 16) {
                  if (visit[a][b] == false && array[a][b] != 1) {

                     stackX.push(a);
                     stackY.push(b);
                     visit[a][b] = true;

                  }
               }
            }
         }
         System.out.println("#" + t + " " + result);
         
         while (!stackX.isEmpty() && !stackY.isEmpty()) {
        	 stackX.pop();
        	 stackY.pop();
         }
      }
   }
}