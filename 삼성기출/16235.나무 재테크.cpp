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
#include <unordered_map>
#include <stack>

using namespace std;

int N, K, M;

int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,-1,0,1 };

// n*n map
// m 개의 나무
// k년이 지난 후

int map1[12][12];//땅의 영양상태

int nut[12][12];

typedef pair<int, int> P;

stack<int> namu[12][12];

vector<pair<int, int> > dead;
//			<age, num>

vector<pair<int, int> > boom;
//			y,	x

void getInput() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map1[i][j] = 5;
			scanf("%d", &nut[i][j]);
		}
	}
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		namu[a][b].push(c);
	}
}

void spring() {
	stack<int> temp;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			stack<int>& now = namu[i][j];

			while (!now.empty()) {
				int nowTop = now.top();

				if (map1[i][j] >= nowTop) {
					map1[i][j] -= nowTop;

					temp.push(nowTop);
				}
				else {
					dead.push_back(make_pair(i * 1000 + j, nowTop));
				}

				now.pop();
			}

			while (!temp.empty()) {
				now.push(++temp.top());
				
				if (temp.top() % 5 == 0)
					boom.push_back(make_pair(i, j));
				temp.pop();
			}

		}
	}
}

void summer() {
	for (int i = 0; i < dead.size(); i++) {
		int y = dead[i].first / 1000;
		int x = dead[i].first % 1000;
		int age = dead[i].second;

		map1[y][x] += age / 2;
	}
	
	dead.clear();
}

void automn() {
	for (int i = 0; i < boom.size(); i++) {
		int y = boom[i].first;
		int x = boom[i].second;

		for (int j = 0; j < 8; j++) {
			int nextY = dy[j] + y;
			int nextX = dx[j] + x;
			if (1 <= nextY && nextY <= N && 1 <= nextX && nextX <= N) {
				namu[nextY][nextX].push(1);
			}
		}
	}

	boom.clear();
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map1[i][j] += nut[i][j];
		}
	}
}

int countTree() {
	int total = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			total += namu[i][j].size();
		}
	}

	return total;
}

void printTreeNum() {
	cout << "------------------------\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", namu[i][j].size());
		}
		for (int j = 1; j <= N; j++) {
			cout.width(4);
			cout << map1[i][j];
		}
		cout << "\n";
	}
}

int main() {
	getInput();

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		automn();
		winter();

		//printTreeNum();
	}

	cout << countTree() << endl;
}