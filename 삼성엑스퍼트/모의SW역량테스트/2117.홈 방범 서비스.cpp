#define _CRT_SECURE_NO_WANRINGS
#define null NULL
#define INF 987654321
#define SHIFT 10

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

int totalPoint;
int cnt;

vector<pair<int, int > > dist;
		// (y,x), dist
vector<pair<int, int> > house;
		
int map1[21][21];

void getInput() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map1[i][j];
			
			if (map1[i][j])
				house.push_back(make_pair(i, j));
		}
	}
}

int checkBenefit(int y, int x, int k) {
	int houseNum = 0;

	if (k == 1)
		return map1[y][x]*M;

	for (int i = 0; i < k; i++) {
		for (int j = -i; j <= i; j++) {
			int py = y - (k-1) + i;
			int px = x + j;

			if (0 <= py && py < N && 0 <= px && px < N) {
				if (map1[py][px])
					houseNum++;
			}
			else {
				if (py < 0 || N <= py)
					break;
			}
		}
	}

	for (int i = 1; i < k; i++) {
		for (int j = i - k + 1; j <= k - i -1; j++) {
			int py = y + i;
			int px = x + j;

			if (0 <= py && py < N && 0 <= px && px < N) {
				if (map1[py][px])
					houseNum++;
			}
			else {
				if (py < 0 || N <= py)
					break;
			}
		}
	}

	return (houseNum*M);
}

int answer() {
	int best=0;

	for (pair<int, int> p : house) { // 400
		for (int k = 1; k <= 23; k++) { // 20cv
			int nowCost = 2 * k*k - 2 * k + 1;
			int nextCost = nowCost + 4 * k;



			int leftend  = checkBenefit(p.first, p.second + (k - 1), k);
			if (leftend >= nowCost){
				best = max(best, leftend);

				if(leftend >= nextCost)
					continue;
			}

			int rightend = checkBenefit(p.first, p.second - (k - 1), k);
			if (rightend >= nowCost) {
				best = max(best, rightend);

				if (rightend >= nextCost)
					continue;
			}

			int topend   = checkBenefit(p.first + (k - 1), p.second, k);
			if (topend >= nowCost) {
				best = max(best, topend);

				if (topend >= nextCost)
					continue;
			}

			int botend   = checkBenefit(p.first - (k - 1), p.second, k);
			if (botend >= nowCost) {
				best = max(best, botend);

				if (botend >= nextCost)
					continue;
			}

			int midend = checkBenefit(p.first, p.second, k);
			if (midend >= nowCost) {
				best = max(best, midend);

				if (midend >= nextCost)
					continue;
			}

			///////////////////////////////
			int leftOne = checkBenefit(p.first, p.second-1, k);
			if (leftOne >= nowCost) {
				best = max(best, leftOne);

				if (leftOne >= nextCost)
					continue;
			}
			int rightOne = checkBenefit(p.first, p.second+1, k);
			if (rightOne >= nowCost) {
				best = max(best, rightOne);

				if (rightOne >= nextCost)
					continue;
			}

			int upOne = checkBenefit(p.first+1, p.second, k);
			if (upOne >= nowCost) {
				best = max(best, upOne);

				if (upOne >= nextCost)
					continue;
			}
			int downOne = checkBenefit(p.first-1, p.second, k);
			if (downOne >= nowCost) {
				best = max(best, downOne);

				if (downOne >= nextCost)
					continue;
			}
			///////////////////////////////


			if (totalPoint < nowCost)
			{
				break;
			}
			int a = 0;

		}

		if (best/M == house.size())
			return house.size();
	}


	return best/M;
}

int answerTest() {
	int best = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			for (int k = 1; k <= 23; k++) { // 20cv
				int nowCost = 2 * k*k - 2 * k + 1;
				int nextCost = nowCost + 4 * k;

				int temp = checkBenefit(i, j, k);
				if (temp >= nowCost) {
					best = max(best, temp);
				}

				if (totalPoint < nowCost)
				{
					break;
				}
			}

			if (best / M == house.size())
				return house.size();
		}
	}


	return best / M;
}



int main() {

	cin >> T;

	for (int tt = 1; tt <= T; tt++){

		getInput();
		totalPoint = house.size()*M;

		cout << "#" << tt <<" "<<answerTest() << endl;
		//참고 answer() 함수는 오답
		// answerTest()가 정답.. 뻘짓했다.

		totalPoint = 0;
		house.clear();
		dist.clear();
	}


	return 0;
}