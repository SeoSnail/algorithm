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
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <string.h>

using namespace std;

int N, M, K;
int T;

int rus[105];
int kor[105];

void getInput() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> rus[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> kor[i];
	}
}

int solve() {
	int answer = 0;
	sort(rus, rus + N);
	sort(kor, kor + N);

	// i : kor, j : rus
	for (int i = 0, j = 0; i < N; i++) {
		if (kor[i] >= rus[j]) {
			answer++;
			j++;
		}
	}

	return answer;
}

int main() {
	cin >> T;

	while (T--) {
		getInput();

		cout << solve() << endl;
	}
}