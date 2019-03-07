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

int N, M, Q;
int T;
int bottleNum[410];
int capa[410];
long long A, B;


void getInput() {
	cin >> A >> B;
}

long long remove4(long long a) { // 층수 a를 9진수로 바꿈. 12356 -> 12345
	long long temp = a;
	long long cnt = 1;
	bool isPlus = true;

	if (a < 0) {
		isPlus = false;
		a = -a;
		temp = a;
	}

	while (temp) {
		if (temp % 10 > 4)
			a -= 1 * cnt;

		cnt *= 10;
		temp /= 10;
	}

	if (isPlus)
		return a;
	else
		return -a;
}

long long invert10(long long a) { // 9진수 a를 10진수로 바꿈
	long long temp = 0;
	long long cnt = 1;
	bool isPlus = true;

	if (a < 0) {
		isPlus = false;
		a = -a;
	}

	while (a) {
		temp += (a % 10)*cnt;

		cnt *= 9;
		a /= 10;
	}
	
	if (isPlus)
		return temp;
	else
		return -temp;
}

long long solve() {
	long long result = 0;
	long long a, b;
	bool isAPlus = true, isBPlus = true;

	if (A < 0)
		isAPlus = false;
	if (B < 0)
		isBPlus = false;

	if (A > B) {
		a = A;
		A = B;
		B = a;
	}

	a = remove4(A);
	b = remove4(B);

	a = invert10(a);
	b = invert10(b);

	result = b - a;

	if (isAPlus != isBPlus)
		result -= 1;

	return result;
}

int main() {
	int local = 0;
	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();
		printf("#%d %lld\n", tt, solve());
	}

}

