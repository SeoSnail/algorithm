#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
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
int Y, X;
int Timee;
int len, nowEat;

//상좌우하
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int map1[25][25];
int possible;

typedef struct shark {
	int y;
	int x;
	int timee;
}shark;

queue<shark> que;

void getInput() {
	cin >> N;

	len = 2;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map1[i][j];

			if (map1[i][j] == 9) {
				X = j;
				Y = i;
				map1[i][j] = 0;
			}
		}
	}
}

bool Eatable(int y, int x) {
	if (map1[y][x] != 0 && map1[y][x] < len)
		return true;
	else
		return false;
}

bool Movable(int y, int x) {
	if (map1[y][x] <= len)
		return true;
	else
		return false;
}

void Growth() {
	nowEat++;

	if (nowEat == len) {
		len++;
		nowEat = 0;
	}
}

int bfs(int i, int j) {
	vector<vector<bool> > visit(N, vector < bool>(N, 0));
	vector<pair<int, int> > suspect;
	int shortest = INF;
	int shortY = N;
	int shortX = N;
	int nextY, nextX;

	shark first;
	first.x = j;
	first.y = i;
	first.timee = 0;
	que.push(first);

	while (!que.empty()) {
		int y = que.front().y;
		int x = que.front().x;
		int timee = que.front().timee;
		que.pop();

		if (shortest < timee || shortY < y)
			continue;
		visit[y][x] = true;
		for (int i = 0; i < 4; i++) {
			nextY = dy[i] + y;
			nextX = dx[i] + x;

			if ((0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
				&& !visit[nextY][nextX]) {
				visit[nextY][nextX] = true;
				if (Eatable(nextY, nextX) && shortest >= timee) { // 먹을수 있고 거리 같은데 y값 크지 않은 것 다 모음

					if (shortest >= timee && shortY >= nextY) {
						shortest = timee;

						if (shortY > nextY) { // 기존 min 보다 y가 더작음
							shortY = nextY;
							shortX = nextX;
						}
						else if (shortY == nextY && shortX > nextX) {
							shortX = nextX;
						}
					}
					suspect.push_back(make_pair(nextY, nextX));
				}
				else if (Movable(nextY, nextX)) {
					shark temp;
					temp.x = nextX, temp.y = nextY, temp.timee = timee + 1;
					que.push(temp);
				}

			}
		}
	}

	if (suspect.size() == 0)
		return -1; // no eatable;
	else {
		sort(suspect.begin(), suspect.end());
		Y = suspect[0].first;
		X = suspect[0].second;
		map1[Y][X] = 0;
		Growth();
		return shortest + 1;
	}
}

int solve() {
	int answer = 0;
	int tester = 3;

	while (1) {
		//if (tester == len) {
		//	printf("len = %d, Timee = %d\n", tester, Timee);
		//	for (int i = 0; i < N; i++) {
		//		for (int j = 0; j < N; j++) {
		//			cout << map1[i][j] << " ";
		//		}
		//		cout << endl;
		//	}
		//	tester++;
		//}
		int timee = bfs(Y, X);

		//		printf("{%d, %d} %d\n", Y, X, len);


		if (timee == -1)
			return Timee;
		else
			Timee += timee;
	}
}

int main() {
	//cin >> T;

	//for (int tt = 1; tt <= T; tt++) {
	//	getInput();

	//	printf("#%d %d\n", tt, solve());

	//}

	getInput();

	cout << solve() << endl;
}