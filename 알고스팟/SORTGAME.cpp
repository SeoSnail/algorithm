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
#include <map>

using namespace std;

vector<int> perm;

int T, N;

map<vector<int>, int> Sorted;


void getInput() {
	cin >> N;
	
	perm = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> perm[i];
	}
}

void preCalc(int n) {
	queue<vector<int> > q;
	vector<int> first(n);
	int cnt = 0;

	for (int i = 0; i < n; i++) first[i] = i;

	Sorted[first] = 0;
	q.push(first);

	while (!q.empty()) {
		vector<int> here = q.front();
		int nowLen = Sorted[here];
		q.pop();
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 2; j <= n; j++) {
				reverse(here.begin() + i, here.begin() + j);

				if (Sorted.count(here) == 0) {
					Sorted[here] = nowLen + 1;
					q.push(here);
				}

				reverse(here.begin() + i, here.begin() + j);
			}
		}
		

		for (int i = 0; i < N; i++)
			cout << here[i] << " ";
		cout << ": " << Sorted[here] << ", " << cnt++ << "\n";

	}

}

int solve(vector<int> perm) {
	vector<int> fixed(N);

	for (int i = 0; i < N; i++) {
		int smaller = 0;
		for (int j = 0; j < N; j++) {
			if (perm[i] > perm[j])
				smaller++;
		}

		fixed[i] = smaller;
	}

	return Sorted[fixed];
}

int main() {
	cin >> T;

	for (int i = 1; i <= 8; i++) {
		preCalc(i);
	}
	while (T--) {
		getInput();
		cout << solve(perm) << endl;
	}
}