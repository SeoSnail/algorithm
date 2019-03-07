#define _CRT_SECURE_NO_WANRINGS
#define null NULL
#define INF 987654321
#define SIZE 1001

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
#include <iterator>

using namespace std;

int N;
int map1[9][9];
vector<vector<bool> > visit;
int K;
int T;
int maxHeight;
int maxLen;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0,0, -1, 1 };

int dfs(int y, int x, int nowHeight, int chance, int len, vector<vector<bool> > visit)
{
	if (nowHeight <= 1 && chance == 1)
		return len;

	int temp = len;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		if (0 <= dy[i] + y && dy[i]+y < N && 0 <= dx[i] + x && dx[i] + x < N) {
			if (!visit[dy[i] + y][dx[i] + x])
			{
				if(nowHeight > map1[dy[i]+y][dx[i]+x])
					temp = max(temp, dfs(dy[i] + y, dx[i] + x, map1[dy[i] + y][dx[i] + x], chance, len + 1, visit) );
				else {
					if (!chance && nowHeight > map1[dy[i] + y][dx[i] + x] - K ) {
						temp = max(temp, dfs(dy[i] + y, dx[i] + x, nowHeight - 1, chance + 1, len + 1, visit) );
					}
				}
			
			}
			
		}
	}

	return temp;
}

int main()
{
	cin >> T;

	for (int tt = 1; tt <= T; tt++)
	{
		maxHeight = 0;
		maxLen = 0;
		cin >> N >> K;

		visit = vector<vector<bool> >(N, vector<bool>(N, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map1[i][j];

				if (maxHeight < map1[i][j])
					maxHeight = map1[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j] && map1[i][j] == maxHeight)
					maxLen = max(maxLen, dfs(i, j, map1[i][j], 0, 1, visit));
			}
		}
		
		cout << "#" << tt << " ";
		cout << maxLen << endl;

	}
}