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


using namespace std;

int T, t, n, N;

vector<int> arr;

int main()
{

	cin >> T;
	

	while (T--)
	{
		int maxi = 0;
		vector<int> stack;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			arr.push_back(a);
		}
		arr.push_back(0);

		for (int i = 0; i < arr.size(); i++)
		{
			while (!stack.empty() && arr[stack.back()] >= arr[i])
			{
				int temp = stack.back();
				stack.pop_back();
				int width = -1;

				if (stack.empty())
					width = i;
				else
					width = (i - stack.back() - 1);

				maxi = max(maxi, arr[temp] * width);
			}

			stack.push_back(i);
		}

		cout << maxi << endl;

		arr.clear();
	}
}