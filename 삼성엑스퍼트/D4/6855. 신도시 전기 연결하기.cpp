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

int A, B;
int a, b, c;
int total = 0;
double dtotal = 0;
long long aa, bb, cc;
string str;

double da;

vector<int> arr;
vector<int> gap;

bool comp(int a, int b) {
	return (a > b) ? true : false;
}

void getInput() {
	cin >> N >> K;

	arr.resize(N);
	gap.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if(i != 0)
			gap[i-1] = arr[i] - arr[i - 1];
	}
}	

int solve() {
	int answer = arr[N-1]-arr[0];

	if (K == 1)
		return answer;
	if (N <= K)
		return 0;

	sort(gap.begin(), gap.end(), comp);

	for (int i = 0; i < K - 1; i++) {
		answer -= gap[i];
	}

	return answer;
}


int main() {
	int T;

	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		cout << "#" << tt << " " << solve() << endl;
	}
}