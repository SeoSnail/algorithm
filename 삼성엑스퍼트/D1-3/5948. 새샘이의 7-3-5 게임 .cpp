#define _CRT_SECURE_NO_WANRINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000

#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <utility>
#include <map>
#include <string.h>
#include <stdlib.h>   
#include <queue>
#include <list>
#include <sstream>

using namespace std;

int N, M;
int T;
int input[8];
vector<int> arr;
int D, A, B, F;

void getInput() {
	for (int i = 0; i < 7; i++)
		scanf("%d", &input[i]);
}

void fillArr(int num, int choose, vector<bool> visit) {
	if (choose == 3) {
		arr.push_back(num);

		return;
	}


	for (int i = 0; i < 7; i++) {
		if (!visit[i]) {
			visit[i] = true;
			fillArr(num + input[i], choose + 1, visit);
		}
	}

}

//slow
int solve() {
	vector<bool> temp(7, false);
	fillArr(0, 0, temp);

	sort(arr.begin(), arr.end());

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	int answer = arr[arr.size()-5]; // 다섯번째로 큰값 = 뒤에서 다섯번째값

	arr.clear();
	
	return answer;
}

int solve2() {
	sort(input, input + 7);

	arr.push_back(input[6] + input[5] + input[1]);
	arr.push_back(input[6] + input[5] + input[2]);

	arr.push_back(input[6] + input[4] + input[3]);
	arr.push_back(input[6] + input[4] + input[2]);

	arr.push_back(input[6] + input[4] + input[1]);
	arr.push_back(input[6] + input[3] + input[2]);
	arr.push_back(input[6] + input[3] + input[1]);

	arr.push_back(input[6] + input[3] + input[0]);
	arr.push_back(input[6] + input[2] + input[1]);
	arr.push_back(input[6] + input[2] + input[0]);

	sort(arr.begin(), arr.end());

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	return arr[arr.size() - 3];
}

int main() {
	int local = 0;
	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %d\n", tt, solve());
	}

}