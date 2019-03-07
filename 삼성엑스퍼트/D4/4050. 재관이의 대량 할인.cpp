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
int total = 0;

vector<int> arr;

bool comp(int a, int b) {
	return ( a > b ? true : false);
}

void getInput() {
	scanf(" %d ", &N);

	arr = vector<int>(N);

	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		total += arr[i];
	}
}

int solve() {
	int answer = total;

	sort(arr.begin(), arr.end(), comp);

	for (int i = 0; i < (N/3)*3; i+=3) {
		answer -= arr[i+2];
	}
	
	arr.clear();
	total = 0;

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