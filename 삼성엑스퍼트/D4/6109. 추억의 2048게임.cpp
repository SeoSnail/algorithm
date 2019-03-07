#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000
#define MOD 1000000007

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <string>

using namespace std;

int N, M;
string state;
int arr[22][22];
int temp[22][22];


void getInput() {
	cin >> N;
	cin >> state;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}

void printArr() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {
	int start, end, adder;

	if (state == "up") {
		start = 1, end = N;
		adder = 1;
	}
	else if (state == "down") {
		start = N, end = 1;
		adder = -1;
	}
	else if (state == "left") {
		start = 1, end = N;
		adder = 1;
	}
	else if (state == "right") {
		start = N, end = 1;
		adder = -1;
	}
	

	if (state == "left" || state == "right"){//left right
		for (int i = start; i != end+adder; i += adder) {
			int zeroNum = 0;

			for (int j = start, cnt = 0; j != end + adder && cnt < abs(start - end); j += adder, cnt++) {
				if (arr[i][j] == 0) {
					for (int k = j; k > 0 && k <= N; k += adder) {
						arr[i][k] = arr[i][k + adder];
					}
					zeroNum++;
					j-=adder;
				}
			}

			for (int j = start; j != end+adder; j += adder) {
				int now = arr[i][j];
				int next = arr[i][j + adder];

				if (zeroNum > abs(j - end))
					break;
				if (now == 0) {
					for (int k = j; k > 0 && k <= N; k += adder) {
						arr[i][k] = arr[i][k + adder];
					}
					zeroNum++;
					j -= adder;
				}
				else {
					if (now == next) {
						arr[i][j] *= 2;
						arr[i][j + adder] = 0;

						zeroNum++;
						for (int k = j + adder; k > 0 && k <= N; k += adder) {
							arr[i][k] = arr[i][k + adder];
						}
					}
				}
			}
		}
	}
	else {// up down
		for (int i = start; i != end+adder; i += adder) {
			int	zeroNum = 0;

			for (int j = start, cnt=0; j != end + adder && cnt < abs(start - end); j += adder, cnt++) {
				if (arr[j][i] == 0) {
					for (int k = j; k > 0 && k <= N; k += adder) {
						arr[k][i] = arr[k + adder][i];
					}
					j -= adder;
					zeroNum++;
				}
			}
			
			for (int j = start; j != end+adder; j += adder) {
				int now = arr[j][i];
				int next = arr[j + adder][i];

				if (zeroNum > abs(j - end))
					break;

				if (now == 0) {
					for (int k = j; k > 0 && k <= N; k += adder) {
						arr[k][i] = arr[k + adder][i];
					}
					zeroNum++;

					j -= adder;
				}
				else {
					if (now == next) {
						arr[j][i] *= 2;
						arr[j + adder][i] = 0;
						zeroNum++;


						for (int k = j + adder; k > 0 && k <= N; k += adder) {
							arr[k][i] = arr[k+adder][i];
						}
					}
				}
			}
		}
	}

	printArr();
}

int main() {
	int T;

	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d\n", tt);
		solve();
	}
}