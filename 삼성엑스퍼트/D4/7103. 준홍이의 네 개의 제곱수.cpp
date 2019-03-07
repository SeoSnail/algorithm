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

int N, M, T;

int jcop[200];

void init() {
	for (int i = 0; i < 200; i++) {
		jcop[i] = i*i;
	}
}

void getInput() {
	cin >> N;
}

int solve() {
	register int ans = 0;

	int sqrtN = sqrt(N);

	for (register int i = 0; i <= sqrtN; i++) {
		int sqrtJ = sqrt(N - jcop[i]);
		for (register int j = i; j <= sqrtJ; j++) {
			int sqrtK = sqrt(N - jcop[i] - jcop[j]);
			for (register int k = j; k <= sqrtK; k++) {
				register double left = N - jcop[i] - jcop[j] - jcop[k];
				
				if (sqrt(left) >= k &&sqrt(left) - int(sqrt(left)) < 0.0000001) {
//					printf("(%d, %d, %d, %.0f)\n", i, j, k, sqrt(left));
					ans++;
				}
			}
		}
	}

	return ans;
}

int main() {
	cin >> T;
	init();

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		cout << "#" << tt<< " " <<solve() << endl;
	}
}