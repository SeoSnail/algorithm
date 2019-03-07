#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000
#define BAKMAN 1000000
#define MOD 1000000007
#define FAC9 362880

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <string.h>

using namespace std;

int N, M, K;
int T;
int Y, X, timee;

int dy[] = { -1, 1, 0 , 0 };
int dx[] = { 0, 0, -1, 1 };
int map1[105][105];
int possible;
vector<vector<bool> > visit;

typedef struct zp {
	int y;
	int x;
	int timer;
}zp;

queue<zp> que;

bool pipes[][4] = {
	{0,0,0,0},
	{ 1,1,1,1 }, //1
	{ 1,1,0,0 }, //2
	{ 0,0,1,1 }, //3
	{ 1,0,0,1 }, //4
	{ 0,1,0,1 }, //5
	{ 0,1,1,0 }, //6
	{ 1,0,1,0 }  //7
};

void getInput() {
	cin >> N >> M >> Y >> X >> timee;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map1[i][j];
		}
	}
}

int solve() {
	int answer = 0;
	visit = vector<vector<bool> >(N, vector<bool>(M, 0));
	possible = 0;

	zp temp;
	temp.y = Y;
	temp.x = X;
	temp.timer = timee;
	visit[Y][X] = true;
	possible++;
	que.push(temp);

	while (!que.empty()) {
		zp f = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) { // 상하좌우 상 가려면 현재 상 가능
									  //+ 다음거 하 가능 해야됨. 이런식으로 pair
			int nextX = f.x + dx[i];
			int nextY = f.y + dy[i];
			int num = map1[f.y][f.x];
			bool nowP = pipes[num][i];
			if (0 <= nextX && nextX < M && 0 <= nextY && nextY < N) {
				if (!visit[nextY][nextX]) {
					bool nextP;
					if (i % 2 == 0)// 짝수(상, 좌) 면 다음 구녕은 하 우
						nextP = pipes[map1[nextY][nextX]][i + 1];
					else // (하, 우) 면
						nextP = pipes[map1[nextY][nextX]][i - 1];

					if (nowP && nextP && f.timer != 1) { // 구멍 맞
						zp temp;
						temp.timer = f.timer - 1;
						temp.x = nextX;
						temp.y = nextY;
						que.push(temp);
						possible++;
						visit[nextY][nextX] = true;
					}
				}
			}
		}
	}
	
	return possible;
}

int main() {
	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %d\n", tt, solve());

	}
}