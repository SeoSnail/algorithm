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

using namespace std;

int T;
int N, arr[50005];

void getInput() {
	cin >> N;

	arr[0] = INF;
	for (int i = 1; i <= N; i++)
		scanf(" %d", &arr[i]);
}

int solve() {
	int result=0;
	int upperCnt = 0;
	int lowerCnt = 0;
	int before, now;
	bool state = false;// true : upper / , false : lower |;

	for (int i = 2; i <= N; i++) {
		before = arr[i - 1];
		now = arr[i];

		if (before > now && state) {
			while (arr[i - 1] > arr[i] && i <= N) {
				lowerCnt++;
				i++;
			}
			i--;
			result += upperCnt*lowerCnt;
			upperCnt = 0;
			lowerCnt = 0;
			state = false;
		}
		else {
			if (before < now) {
				upperCnt++;
				state = true;
			}
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
	}

}

