package backjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node {
   int x;
   int y;
   int d;
   
   Node(){
      
   }

   Node(int x, int y, int d) {
      this.x = x;
      this.y = y;
      this.d = d;
   }
}

public class Main {
   static int N;
   static int size = 2;
   static int eat = 0;
   static int start_x = 0;
   static int start_y = 0;
   static int start_d = 0;
   static int time = 0;
   static int fish[][];
   static boolean visit[][];
   static int dx[] = { -1, 0, 1, 0 };
   static int dy[] = { 0, 1, 0, -1 };
   
   static ArrayList<Node> list = new ArrayList<Node>();

   public static void bfs(int start_x, int start_y,int start_d) {
      int result = 0;
      Queue<Node> q = new LinkedList<Node>();
      
      q.add(new Node(start_x, start_y, start_d)); // 아기상어 위치 큐에 저장
      visit[start_x][start_y] = true;

      while (!q.isEmpty()) {
         Node n = q.poll();
               
         //맵에 물고기가 먹을수 있는 고기가 없으면 종료
                  
         //4방향으로 탐색
         for (int i = 0; i < 4; i++) {
            int a = n.x + dx[i]; //다음 x좌표
            int b = n.y + dy[i]; //다음 y좌표
            
            if (a >= 0 && a < N && b >= 0 & b < N) {
               if (visit[a][b] == false) {
                  // 아기상어의 크기보다 작거나 같으면 이동만가능
                  if (fish[a][b] <= size) { 
                     q.add(new Node(a, b, n.d+1));
                     visit[a][b] = true;
                     
                     // 아기상어랑 크기가 같으면 먹지 못한다
                     if(fish[a][b] == size) {
                        continue;
                     }
                     
                     //먹을 수 있으니까 Arraylist에 담기
                     if(fish[a][b] != 0) {
                        list.add(new Node(a, b, n.d+1));                       
                     }
                  }
               }
            }
         }         
      }
   }
   
   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st;
         
      st = new StringTokenizer(br.readLine());      
      N = Integer.parseInt(st.nextToken());
      fish = new int[N + 1][N + 1];
      visit = new boolean[N + 1][N + 1];
      
      // 물고기 위치 입력
      for (int i = 0; i < N; i++) {
         st = new StringTokenizer(br.readLine());
         for (int j = 0; j < N; j++) {
            fish[i][j] = Integer.parseInt(st.nextToken());

            if (fish[i][j] == 9) {
               start_x = i;
               start_y = j;
               visit[i][j] = true;
            }
         }
      }
      while(true) {
         bfs(start_x, start_y,start_d);
                         
         //ArrayList에 담긴게 없으면(먹은게 없으면)종료
         if(list.size() == 0) {
        	 break;
         }
            
         //ArrayList 정렬
         Collections.sort(list, new Comparator<Node>() {

            @Override
            public int compare(Node p1, Node p2) {
               //거리가 같으면
               if(p1.d == p2.d) {
            	   //거리가 같고 x좌표가 다르면 x좌표가 더 작은거(위로 먼저 감)
            	   if(p1.x != p2.x)
            		   return p1.x - p2.x;
            	   //거리가 같고 x좌표도 같으면 y 좌표가 더 작은거(왼쪽으로 먼저감)
            	   else if(p1.x == p2.x)
            		   return p1.y - p2.y;                 
               }                           
               //거리가 다르면 거리가 더 짧은걸로
               if(p1.d!= p2.d) {
                  return p1.d - p2.d;
               }
               return 0;            
            }         
         });
             
         Node begin = list.get(0); //정렬해서 첫번째 list를 Node 타입 변수에 담아줌        
         list.clear(); //리스트를 없애쥼
         eat++; //먹이증가
         
         //먹은게 상어 크기랑 같으면 상어크기 증가하고 먹은거 초기화
         if(size == eat) {
        	 size++;
        	 eat =0;        	 
         }
         
         fish[start_x][start_y] = 0; //처음에 시작했던점을 0으로 바꿔줌
         //시작점을 arrayList에 첫번째 값으로 다시 바꿔쥼
         start_x = begin.x;
         start_y = begin.y;
         start_d = begin.d;
               
         fish[start_x][start_y] = 9; //아기 상어 위치 설정
         
         for(int i = 0; i<N; i++) {
        	 for(int j = 0; j<N; j++) {
        		 Arrays.fill(visit[i], false); //배열의 주소를 모두 같은 값으로 초기화
        	 }
         }
               
         visit[start_x][start_y] = true;
      }   
      
      System.out.println(start_d);
   }
}