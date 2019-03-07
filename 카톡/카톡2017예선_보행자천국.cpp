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

int MOD = 20170805;


void printDP() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << leftdp[i][j] + updp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
}

void printLEFT() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << leftdp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
}

void printUP() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << updp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> city) {
	int answer = 0;
	vector<vector<int> > leftdp;
	vector<vector<int> > updp;

	leftdp = vector<vector<int>>(n, vector<int>(m, 0));
	updp = vector<vector<int>>(n, vector<int>(m, 0));

	leftdp[0][0] = 1;
	updp[0][0] = 1;

	for (int i = 1; i < m; i++)
	{
		if (city[0][i] != 1)
		{
			leftdp[0][i] = leftdp[0][i - 1];
		}
	}
	if (city[0][m - 1] == 2)
	{
		leftdp[0][m - 1] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (city[i][0] != 1)
		{
			updp[i][0] = updp[i - 1][0];
		}
	}
	if (city[n - 1][0] == 2)
	{
		updp[n - 1][0] = 0;
	}


	// init end
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			switch (city[i][j])
			{
			case 0:
				// up check
				if (city[i - 1][j] == 2)
				{
					int temp = i - 1;

					while (temp >= 0 && city[temp][j] == 2)
						temp--;

					if (temp >= 0)
						updp[i][j] = (updp[temp][j]+leftdp[temp][j])%MOD;
					else
						updp[i][j] = 0;
				}
				else if (city[i - 1][j] == 0)
					updp[i][j] = (leftdp[i - 1][j] + updp[i - 1][j]) % MOD;
				else
					updp[i][j] = 0;
				//up check end

				//left check
				if (city[i][j - 1] == 2)
				{
					int temp = j - 1;

					while (temp >= 0 && city[i][temp] == 2)
						temp--;

					if (temp >= 0)
						leftdp[i][j] = (leftdp[i][temp]+updp[i][temp]) % MOD;
					else
						leftdp[i][j] = 0;
				}
				else if (city[i][j - 1] == 0)
					leftdp[i][j] = (leftdp[i][j - 1] + updp[i][j - 1]) % MOD;
				else
					leftdp[i][j] = 0;
				//left check end

				break;
			case 2:
				// up check
				if (city[i - 1][j] == 2)
				{
					int temp = i - 1;

					while (temp >= 0 && city[temp][j] == 2)
						temp--;

					if (temp >= 0)
						updp[i][j] = (updp[temp][j]+leftdp[temp][j]) % MOD;
					else
						updp[i][j] = 0;
				}
				else if (city[i - 1][j] == 0)
				{
					//mosorry check
					if (i == n - 1)
						updp[i][j] = 0;
					else
						updp[i][j] = (leftdp[i - 1][j] + updp[i - 1][j]) % MOD;
				}
				else
					updp[i][j] = 0;
				//up check end

				//left check
				if (city[i][j - 1] == 2)
				{
					int temp = j - 1;

					while (temp >= 0 && city[i][temp] == 2)
						temp--;

					if (temp >= 0)
						leftdp[i][j] = (leftdp[i][temp]+updp[i][temp]) % MOD;
					else
						leftdp[i][j] = 0;
				}
				else if (city[i][j - 1] == 0)
				{
					//mosorry check
					if (j == m - 1)
						leftdp[i][j] = 0;
					else
						leftdp[i][j] = (leftdp[i][j - 1] + updp[i][j - 1]) % MOD;
				}
				else
					leftdp[i][j] = 0;
				//left check end

				break;
			case 1:
				leftdp[i][j] = 0;
				updp[i][j] = 0;
				break;
			}
		}
	}



	answer = (leftdp[n - 1][m - 1] + updp[n - 1][m - 1]) % MOD;
	return answer;
}

int main() {
	vector<vector<int>> test;
	vector<vector<int>> test2;

	test.push_back({ 0, 2, 0,0,0, 2 });
	test.push_back({ 0,0,2,0,1,0 });
	test.push_back({ 1,0,0,2,2,0 });
	

	test2.push_back({ 0,0,0,0,0});
	test2.push_back({ 0,0,0,0,0 });
	test2.push_back({ 0,0,0,0,0 });

//	cout << solution(test.size(), test[0].size(), test);

	cout << solution(test.size(), test[0].size(), test) <<endl;


	return 0;
}