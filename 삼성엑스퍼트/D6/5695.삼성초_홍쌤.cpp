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
int T;

int start;

bool visit[1001];
int maxCycle, TreeSum;
int arr[1001];
int pairNum = 0;
bool nowVisit[1001];
vector<int> nowVisitIndex;
vector<vector<int> > Tree;

int dfs(int n, int len, int Pair) {
	if (Tree[n].size() == 1 && Tree[n][0] == Pair)
		return 0;
	int temp = len;

	for (int i = 0; i < Tree[n].size(); i++)
	{
		if (Tree[n][i] == Pair)
			continue;
		temp = max(temp, dfs(Tree[n][i], len+1, Pair));
	}
	len = temp;

	return len;
}

int main() {

	cin >> T;
	int FT = T;

	while (T--)
	{
		cnt = 0;
		pairNum = 0;
		maxCycle = TreeSum = 0;
		memset(arr, 0, sizeof arr);
		memset(visit, 0, sizeof visit); 
		
		cin >> N;
		Tree = vector<vector<int> >(N+1);
		
		for (int i = 1; i <= N; i++)
		{
			cin >> arr[i];

			Tree[arr[i]].push_back(i);
		}

		//find cycle
		for (int i = 1; i <= N; i++)
		{
			bool flag = false;
			memset(nowVisit, 0, sizeof nowVisit);
			nowVisitIndex.clear();
			cnt = 1;

			if (!visit[arr[i]])
			{
				nowVisit[i] = true;
				nowVisitIndex.push_back(i);
				int first;

				int j = arr[i];
				while (1)
				{
					if (visit[j])
					{
						flag = true;
						break;
					}
					if (nowVisit[j])
					{
						first = j;
						break;
					}
					nowVisit[j] = true;

					j = arr[j];

				}

				if (!flag)
				{
					j = arr[first];
					while (j != first) {
						cnt++;
						j = arr[j];
					}
				}

				for (int i : nowVisitIndex)
					visit[i] = true;

				if (maxCycle < cnt)
					maxCycle = cnt;
			}
		}
		// cycle end


		memset(visit, 0, sizeof visit);

		TreeSum = 0;
		for (int i = 1; i <= N; i++)
		{

			if (!visit[i] && i == arr[arr[i]])
			{
				visit[i] = visit[arr[i]] = true;
				int first = i, second = arr[i];

				TreeSum += 2+ dfs(first, 0, second) + dfs(second, 0, first) ;
			}
		}


		cout << "#"<< FT-T << " "<< max(maxCycle, TreeSum) << endl;


		
	}


	return 0;
}