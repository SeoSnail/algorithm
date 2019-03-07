#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000
#define BAKMAN 1000001
#define MOD 1000000007

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <string.h>

using namespace std;

int N, M;

int A, B;

int cache[5][5];

void getInput() {
	cin >> A >> B;
}


void init() {
	cache[0][0] = 0;
	cache[0][1] = 0;
	cache[0][2] = 0;
	cache[0][3] = 0;
	cache[0][4] = 0;

	cache[1][1] = 1;
	cache[1][2] = 2;
	cache[1][3] = 2;
	cache[1][4] = 2;

	cache[2][2] = 3;
	cache[2][3] = 4;
	cache[2][4] = 4;

	cache[3][3] = 5;
	cache[3][4] = 6;

	cache[4][4] = 8;
	

	for (int i = 0; i <= 4; i++) {
		for (int j = i + 1; j <= 4; j++) {
			cache[j][i] = cache[i][j];
		}
	}

}


long long solve() {
	int answer = 0;
	int row, col;
	int leftR, leftC;
	int temp;


	if (A <= 4 && B <= 4)
		return cache[A][B];

	row = A / 4;
	col = B / 4;

	answer += row*col * 8;

	leftR = A % 4;
	leftC = B % 4;
	
	answer += col*cache[leftR][4];
	answer += row*cache[4][leftC];
	answer += cache[leftR][leftC];


	return answer;
}

int main() {
	int T;

	cin >> T;

	init();

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %lld\n", tt, solve());
	}
}