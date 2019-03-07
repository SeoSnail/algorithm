#pragma warning(disable: 4996)
#define null NULL
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <string.h>

using namespace std;

int N, T, M, cnt;

int arr[1005];
			//cnt, num
void getInput() {
	cin >> N;

	memset(arr, 0, sizeof(arr));
	
	for (int i = 0; i < 1000; i++) {
		int temp;
		scanf("%d", &temp);

		arr[temp]++;
	}
}

int solve() {
	int maxi = 0;
	int index = 0;
	for (int i = 0; i < 1000; i++) {
		if (maxi <= arr[i]) {
			maxi = arr[i];
			index = i;
		}
	}

	return index;
}

int main() {

	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %d\n", tt, solve());
	}
}