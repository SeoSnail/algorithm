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
vector<int> gap;

void getInput() {
	scanf(" %d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		arr.push_back(A);
	}
}

int solve() {
	int answer = 0;

	sort(arr.begin(), arr.end());

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 1; i < arr.size(); i++) {
		gap.push_back(arr[i] - arr[i - 1]);
	}

	sort(gap.begin(), gap.end());

	if (gap.size() <= M - 1)
		answer = 0;
	else
		for (int i = 0; i < gap.size()-M+1; i++)
			answer += gap[i];

	
	arr.clear();
	gap.clear();

	return answer;
}

int main() {
	int T;

	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %d\n", tt, solve());
	}
}