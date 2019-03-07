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

vector<int> arr;

void getInput() {
	scanf(" %d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		arr.push_back(A);
	}
}

double solve() {
	double answer = 0;

	sort(arr.begin(), arr.end());

	
	for (int i = N - M; i < N; i++) {
		answer = (answer + (double)arr[i]) / 2.0;
	}
	
	arr.clear();

	return answer;
}

int main() {
	int T;

	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %lf\n", tt, solve());
	}
}