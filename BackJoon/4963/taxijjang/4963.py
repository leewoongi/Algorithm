import sys
sys.setrecursionlimit(10000)
def dfs(x,y,visited,board, n , m):
    visited[x][y] = True

    for dx,dy in (-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1):
        nx,ny = x + dx, y + dy

        if nx <0 or nx >=n or ny <0 or ny >=m or visited[nx][ny] == True or board[nx][ny] == 0:
            continue

        dfs(nx,ny,visited,board,n,m)

while True:
    m,n = map(int,sys.stdin.readline().split())

    if n== 0 and m ==0:
        break

    visited = [[False]*m for _ in range(n)]

    board = []

    for _ in range(n):
        board.append(list(map(int,sys.stdin.readline().split())))
    
    res = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j] == False and board[i][j] == 1:
                dfs(i,j,visited,board, n , m)
                res+=1

    print(res)
