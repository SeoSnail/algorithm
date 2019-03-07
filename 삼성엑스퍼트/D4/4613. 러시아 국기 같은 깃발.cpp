#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000

/*

*/

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <utility>
#include <map>
#include <string.h>
#include <stdlib.h>   
#include <queue>
#include <list>
#include <sstream>

#include <stack>

#define WHITE 0
#define BLUE 1
#define RED 2

using namespace std;

int N, M, Q;
int T;
string board[55];
int Color[55][3]; //[col][WBR];

void getInput() {
	string str;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
		for (int j = 0; j < M; j++) {

			switch (board[i][j]) {
			case 'W':
				Color[i][WHITE]++;
				break;
			case 'B':
				Color[i][BLUE]++;
				break;
			case 'R':
				Color[i][RED]++;
				break;
			}
		}
	}


}

int calcChange(int x, int y) {
	int total = N*M;

	for (int i = 0; i < x; i++)
		total -= Color[i][WHITE];

	for (int i = x; i < y; i++)
		total -= Color[i][BLUE];

	for (int i = y; i < N; i++)
		total -= Color[i][RED];

	return total;
}

long long solve() {
	int result=INF;
	int local = 0;

	// i j : 색깔 경계선 경우의수 
	// 0~i-1 : white
	// i~j-1 : blue
	// j~N-1 : red
	for (int i = 1; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			local = calcChange(i, j);

			if (local < result)
				result = local;
		}
	}

	return result;
}

int main() {
	int local = 0;
	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();
		printf("#%d %d\n", tt, solve());

		for (int i = 0; i < 55; i++)
			for(int j=0; j<3; j++)
				Color[i][j] = 0;
	}

}

