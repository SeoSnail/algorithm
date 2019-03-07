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

int D, A, B, F;

void getInput() {
	cin >> D >> A >> B >> F;
}

double solve() {
	double hour = (double)D / (double)(A + B);

	return (double)hour*(double)F;
}

int main() {
	int local = 0;
	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %.7lf\n", tt, solve());
	}

}