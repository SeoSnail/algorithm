#define _CRT_SECURE_NO_WANRINGS
#define null NULL
#define INF 987654321

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

int N;
int cnt;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int dp[1000001];

int solution(vector<int> money) {
	int answer = 0;
	int aa, bb;
	
	dp[0] = money[0];
	dp[1] = money[0];


	for (int i = 2; i < money.size()-1; i++)
	{
		dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
	}
	aa = dp[money.size() - 2];

	dp[0] = 0;
	dp[1] = money[1];

	for (int i = 2; i < money.size(); i++)
	{
		dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
	}
	bb = dp[money.size() - 1];

	answer = max(aa, bb);

	return answer;
}

int main() {


	return 0;
}