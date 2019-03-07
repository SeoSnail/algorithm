#pragma warning(disable: 4996)
#define null NULL
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>

using namespace std;

int arr[1000005];

int afterMax[1000005];

int N, T, M, cnt;

void getInput() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		afterMax[i] = max(afterMax[i+1], arr[i]);
	}
}

long long solve() {
	long long total =0;

	for (int i = 0; i < N; i++) {
		if (arr[i] < afterMax[i]) {
			total += afterMax[i] - arr[i];
		}
	}

	return total;
}

int main() {

	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %lld\n", tt, solve());
	}
}