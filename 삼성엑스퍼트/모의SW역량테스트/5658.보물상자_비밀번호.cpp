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


map<string, int> arr;

string str;
int N, n, k;
int T;

vector<int> sortedArr;

int main() {
	cin >> T;

	for (int tt = 1; tt <= T; tt++)
	{
		cin >> N >> k;

		cin >> str;

		for (int k = 0; k < 7; k++)
		{
			for (int i = 0; i < 4; i++)
			{
				string sub = str.substr(i * N / 4, N / 4);

				arr[sub]++;
			}

			str = str.append(str.begin(), str.begin() + 1);
			str.erase(str.begin(), str.begin() + 1);
		}


		for (map<string, int>::iterator it = arr.begin(); it != arr.end(); it++)
		{
			int num = stoi(it->first, nullptr, 16);

			sortedArr.push_back(num);
		}

		sort(sortedArr.begin(), sortedArr.end());
		reverse(sortedArr.begin(), sortedArr.end());

		cout << "#" << tt << " ";
		cout << sortedArr[k - 1] << endl;

		sortedArr.clear();
		arr.clear();
	}
}