#define _CRT_SECURE_NO_WANRINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000

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

using namespace std;

int N, M;
int T;

int dp[1000];

bool isSosu[1000];

vector<int> Sortsosu;



void calcSosu() {
	isSosu[0] = false;
	isSosu[1] = false;
	isSosu[2] = true;

	for (int i = 3; i < 1000; i++) {
		isSosu[i] = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				isSosu[i] = false;
				break;
			}
		}
	}
}

void calcDP() {
	for (int i = 4; i < 1000; i++) {
		int localSum = 0;
		for (auto j : Sortsosu) {
			if (i < j)
				break;
			if (j <= i-j && isSosu[i - j])
				localSum++;
		}

		dp[i] = localSum;
	}
}

int solve(int n) {
	int local = 0;
	for (auto i : Sortsosu) {
		for (auto j : Sortsosu) {
			if (i > j)
				continue;
			
			if (n-(i+j) >= j && n > i + j && isSosu[n - (i + j)])
				local++;
		}
	}

	return local;
}

int recur(int n, int cnt, int before) {
	int num = 0;

	if (cnt == 2 && isSosu[n]) {
		if (before <= n)
			return 1;
		else
			return 0;
	}

	if (n < 2)
		return 0;


	for (auto i : Sortsosu) {
		if (i < before)
			continue;
		if (n < i)
			break;

		num += recur(n - i, cnt + 1, i);
	}
	return num;
}

int main() {
	int local = 0;
	cin >> T;

	calcSosu();

	for (int i = 1; i < 1000; i++) {
		if (isSosu[i]) {
			Sortsosu.push_back(i);
			local++;
		}
	}

	calcDP();

	for (int tt = 1; tt <= T; tt++) {
		cin >> N;

		printf("#%d %d\n", tt, solve(N));
	}
}