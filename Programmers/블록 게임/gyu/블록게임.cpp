#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int map[50][50];

void init_map(vector<vector<int>>board, int board_y_size, int board_x_size, bool flag)
{
   if (flag)
   {
      for (int i = 0; i < board_y_size; i++)
      {
         for (int j = 0; j < board_x_size; j++)
         {
            if (map[i][j] != board[i][j] && map[i][j] >= 0)
            {
               map[i][j] = 0;
            }
            else
            {
               map[i][j] = board[i][j];
            }
         }
      }
   }
}

void init_map_2(vector<vector<int>>board, int board_y_size, int board_x_size, bool flag)
{

   for (int i = 0; i < board_y_size; i++)
   {
      for (int j = 0; j < board_x_size; j++)
      {
         map[i][j] = board[i][j];
      }
   }
}

int solution(vector<vector<int>> board)
{
   bool flag = false;
   int answer = 0;
   int board_y_size = board.size();
   int board_x_size = 0;
   bool top_board_zero_check = false;
   for (int i = 0; i < board_y_size; i++)
   {
      if (board_x_size < board[i].size())
      {
         board_x_size = board[i].size();
      }
   }
   for (int i = 0; i < board_x_size; i++)
   {
      if (board[0][i] == 0)
      {
         top_board_zero_check = true;
      }
   }
   if (!top_board_zero_check)
   {
      return 0;
   }
   init_map_2(board, board_y_size, board_x_size, flag);
   int c = 0;
   bool sero_check;
   while (1) //전체 반복
   {
      flag = false;
      c = 0;
      while (1)//두칸에 한개씩 블럭
      {
         if (c >= board_y_size)
         {
            break;
         }
         sero_check = false;

         for (int i = c; i < c + 2; i++)
         {
            for (int j = 0; j < board_y_size; j++)
            {
               if (j - 1 == -1 && map[j][i] > 0)
               {
                  break;
               }
               if (map[j][i] > 0)
               {
                  map[j - 1][i] = map[j][i];
                  break;
               }
            }
         }

         for (int i = 0; i < board_y_size - 1; i++)
         {
            for (int j = 0; j < board_x_size; j++)
            {
               if (i + 1 < board_y_size && j - 1 > -1 && j - 2 > -1)
               {
                  if (map[i][j] == map[i + 1][j] && map[i][j] == map[i][j - 1] && map[i][j] == map[i + 1][j - 1] && map[i][j] == map[i + 1][j - 2] && map[i][j] == map[i][j - 2])
                  {
                     if (map[i][j] != 0 && map[i + 1][j] != 0 && map[i][j - 1] != 0 && map[i + 1][j - 1] != 0 && map[i][j - 2] != 0)
                     {
                        map[i][j] = 0;
                        map[i + 1][j] = 0;
                        map[i][j - 1] = 0;
                        map[i + 1][j - 1] = 0;
                        map[i + 1][j - 2] = 0;
                        map[i][j - 2] = 0;
                        answer++;
                        flag = true;
                        c = 0;
                     }
                  }
               }
            }
         }
         for (int i = 0; i < board_y_size; i++)
         {
            for (int j = 0; j < board_x_size; j++)
            {
               if (i - 1 > -1 && i - 2 > -1 && j - 1 > -1)
               {
                  if (map[i][j] == map[i - 1][j] && map[i][j] == map[i - 2][j] && map[i][j] == map[i][j - 1] && map[i][j] == map[i - 1][j - 1] && map[i][j] == map[i - 2][j - 1])
                  {
                     if (map[i][j] != 0 && map[i - 1][j] != 0 && map[i - 2][j] != 0 && map[i][j - 1] != 0 && map[i - 1][j - 1] != 0 && map[i - 2][j - 1] != 0)
                     {
                        map[i][j] = 0;
                        map[i - 1][j] = 0;
                        map[i - 2][j] = 0;
                        map[i][j - 1] = 0;
                        map[i - 1][j - 1] = 0;
                        map[i - 2][j - 1] = 0;
                        answer++;
                        flag = true;
                        c = 0;
                     }
                  }

               }

            }
         }
         c++;

         init_map(board, board_y_size, board_x_size, true);
      }
      c = 0;
      while (1)//한칸에 두개의 블럭
      {
         if (c >= board_y_size)
         {
            break;
         }
         for (int i = c; i < c + 1; i++)
         {
            for (int j = 0; j < board_y_size; j++)
            {
               if (j - 1 <= -1 && j - 2 <= -1 && map[j][i] > 0)
               {
                  break;
               }
               if (map[j][i] > 0)
               {
                  map[j - 1][i] = map[j][i];
                  map[j - 2][i] = map[j - 1][i];
                  break;
               }
            }
         }
         for (int i = 0; i < board_y_size - 1; i++)
         {
            for (int j = 0; j < board_x_size; j++)
            {
               if (i + 1 < board_y_size && j - 1 > -1 && j - 2 > -1)
               {
                  if (map[i][j] == map[i + 1][j] && map[i][j] == map[i][j - 1] && map[i][j] == map[i + 1][j - 1] && map[i][j] == map[i + 1][j - 2] && map[i][j] == map[i][j - 2])
                  {
                     if (map[i][j] != 0 && map[i + 1][j] != 0 && map[i][j - 1] != 0 && map[i + 1][j - 1] != 0 && map[i][j - 2] != 0)
                     {
                        map[i][j] = 0;
                        map[i + 1][j] = 0;
                        map[i][j - 1] = 0;
                        map[i + 1][j - 1] = 0;
                        map[i + 1][j - 2] = 0;
                        map[i][j - 2] = 0;
                        answer++;
                        flag = true;
                        c = 0;
                     }
                  }
               }
            }
         }
         for (int i = 0; i < board_y_size; i++)
         {
            for (int j = 0; j < board_x_size; j++)
            {
               if (i - 1 > -1 && i - 2 > -1 && j - 1 > -1)
               {
                  if (map[i][j] == map[i - 1][j] && map[i][j] == map[i - 2][j] && map[i][j] == map[i][j - 1] && map[i][j] == map[i - 1][j - 1] && map[i][j] == map[i - 2][j - 1])
                  {
                     if (map[i][j] != 0 && map[i - 1][j] != 0 && map[i - 2][j] != 0 && map[i][j - 1] != 0 && map[i - 1][j - 1] != 0 && map[i - 2][j - 1] != 0)
                     {
                        map[i][j] = 0;
                        map[i - 1][j] = 0;
                        map[i - 2][j] = 0;
                        map[i][j - 1] = 0;
                        map[i - 1][j - 1] = 0;
                        map[i - 2][j - 1] = 0;
                        answer++;
                        flag = true;
                        c = 0;
                     }
                  }
               }
            }
         }
         c++;

         init_map(board, board_y_size, board_x_size, true);
      }
      c = 0;
      while (1)//두칸 뛰엄 하기
      {
         if (c >= board_y_size)
         {
            break;
         }
         sero_check = false;

         for (int i = c; i < c + 3; i=i+2)
         {
            for (int j = 0; j < board_y_size; j++)
            {
               if (j - 1 == -1 && map[j][i] > 0)
               {
                  break;
               }
               if (map[j][i] > 0)
               {
                  map[j - 1][i] = map[j][i];
                  break;
               }
            }
         }

         for (int i = 0; i < board_y_size - 1; i++)
         {
            for (int j = 0; j < board_x_size; j++)
            {
               if (i + 1 < board_y_size && j - 1 > -1 && j - 2 > -1)
               {
                  if (map[i][j] == map[i + 1][j] && map[i][j] == map[i][j - 1] && map[i][j] == map[i + 1][j - 1] && map[i][j] == map[i + 1][j - 2] && map[i][j] == map[i][j - 2])
                  {
                     if (map[i][j] != 0 && map[i + 1][j] != 0 && map[i][j - 1] != 0 && map[i + 1][j - 1] != 0 && map[i][j - 2] != 0)
                     {
                        map[i][j] = 0;
                        map[i + 1][j] = 0;
                        map[i][j - 1] = 0;
                        map[i + 1][j - 1] = 0;
                        map[i + 1][j - 2] = 0;
                        map[i][j - 2] = 0;
                        answer++;
                        flag = true;
                        c = 0;
                     }
                  }
               }
            }
         }
         for (int i = 0; i < board_y_size; i++)
         {
            for (int j = 0; j < board_x_size; j++)
            {
               if (i - 1 > -1 && i - 2 > -1 && j - 1 > -1)
               {
                  if (map[i][j] == map[i - 1][j] && map[i][j] == map[i - 2][j] && map[i][j] == map[i][j - 1] && map[i][j] == map[i - 1][j - 1] && map[i][j] == map[i - 2][j - 1])
                  {
                     if (map[i][j] != 0 && map[i - 1][j] != 0 && map[i - 2][j] != 0 && map[i][j - 1] != 0 && map[i - 1][j - 1] != 0 && map[i - 2][j - 1] != 0)
                     {
                        map[i][j] = 0;
                        map[i - 1][j] = 0;
                        map[i - 2][j] = 0;
                        map[i][j - 1] = 0;
                        map[i - 1][j - 1] = 0;
                        map[i - 2][j - 1] = 0;
                        answer++;
                        flag = true;
                        c = 0;
                     }
                  }

               }

            }
         }
         c++;

         init_map(board, board_y_size, board_x_size, true);
      }
      if (!flag)
      {
         break;
      }
   }
   return answer;
}

int main()
{
   /*vector<vector<int>> board =
   {
   {0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,0,0,0,4,0,0,0}
   ,{0,0,0,0,0,4,4,0,0,0}
   ,{0,0,0,0,3,0,4,0,0,0}
   ,{0,0,0,2,3,0,0,0,5,5}
   ,{1,2,2,2,3,3,0,0,0,5}
   ,{1,1,1,0,0,0,0,0,0,5}
   };
   /*vector<vector<int>> board=
   {{1,1,1,1,0,7,0,0,0,0}
   ,{0,0,0,0,0,7,0,0,0,0}
   ,{0,0,0,6,7,7,0,0,0,0}
   ,{0,0,0,6,6,6,0,0,0,0}
   ,{0,0,0,2,2,0,0,0,0,0}
   ,{0,0,0,2,1,0,0,0,0,0}
   ,{9,0,0,2,1,0,0,0,0,0}
   ,{9,0,0,0,1,1,0,0,4,4}
   ,{9,9,8,0,0,5,0,0,3,4}
   ,{8,8,8,5,5,5,3,3,3,4}
   };*/
   vector<vector<int>> board =
   { {0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,2,2,0,0,0,0,0}
   ,{0,4,0,2,1,0,0,0,0,0}
   ,{4,4,4,2,1,0,0,3,0,0}
   ,{0,0,0,0,1,1,3,3,3,0}
   ,{0,0,0,0,0,0,0,0,0,0}
   ,{0,0,0,0,0,0,0,0,0,0} };

   cout << solution(board) << endl;
}