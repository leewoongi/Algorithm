#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct Shark {
	
	int x;
	int y;
	int dis;

}shark;

int map[21][21];
bool visit[21][21];
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

void v_init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}


queue<shark> q;
vector<shark> v;
void fish_check(int start_x, int start_y, int s_size, int n) {

	q.push({ start_x, start_y, 0 });
	visit[start_x][start_y] = true;

	while (!q.empty()) {

		shark s = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = s.x + dir_x[i];
			int next_y = s.y + dir_y[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
				if (visit[next_x][next_y] == false) {

					// map == 0 && map == size
					if (map[next_x][next_y] == 0 || map[next_x][next_y] == s_size) {
						// x, y,  dis + 1
						visit[next_x][next_y] = true;
						q.push({ next_x, next_y, s.dis + 1 });
					}

					// map != 0 map < size 
					else if (map[next_x][next_y] != 0 && map[next_x][next_y] < s_size) {
						// x, y, dis+1
						visit[next_x][next_y] = true;
						v.push_back({ next_x,next_y,s.dis + 1 });
						q.push({ next_x, next_y, s.dis + 1 });
					}

					// map > size
				}
			}
		}
	}
}

bool cmp(const shark &x, const shark &y) {
	// 거리가 같다면
	if (x.dis == y.dis) {
		
		//가장 위에 같을 때
		if (x.x == y.x) {
			
			//가장 왼쪽 꺼
			return x.y < y.y;
		}
		else {
			//x의 값이 작아야지 위에 있음
			return x.x < y.x;
		}
	}
	else {
		return x.dis < y.dis;
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int start_x, start_y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start_x = i;
				start_y = j;

				//시작점알았으니까 시작점 바로 0으로 바꿔버리기
				map[i][j] = 0;
			}
		}
	}

	int s_size = 2;
	int s_eat = 0;
	int move = 0;


	while (true) {

		//visit배열 초기화

		v_init(n);
		
		//물고기 확인하러가기
		fish_check(start_x, start_y, s_size, n);

		//sort, 자기자신보다 작은 물고기들 체크
		sort(v.begin(), v.end(), cmp);

		int end = v.size();
		//종료 조건
		if (end == 0) {
			break;
		}

		// 먹은거 체크
		if (end != 0) {
			s_eat = s_eat + 1;

			//먹은거 0으로 바꾸기
			map[v[0].x][v[0].y] = 0;
		}
		// 상어크기 만큼 먹으면 상어크기 증가 및 먹은갯수 다시 0으로 초기화
		if (s_eat == s_size) {
			s_size = s_size + 1;
			s_eat = 0;
		}

		//시작점바꿔주기
		start_x = v[0].x;
		start_y = v[0].y;
		move = move + v[0].dis;
		
		//vector안에 있는 값 지우기
		for (int i = 0; i < end; i++) {
			v.pop_back();
		}
		
	}
	
	

	cout << move;
	return 0;
}