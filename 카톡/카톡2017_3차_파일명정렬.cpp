#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WANRINGS

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
#include <locale> 

#include <time.h>
#include <ctime>
#include <queue>

using namespace std;

typedef struct data {
	int num;
	string head;
	int mid;
}Data;

bool com_by_head(Data a, Data b)
{
	return (a.head < b.head) ? true : false ;
}

bool com_by_mid(Data a, Data b)
{
	return (a.mid < b.mid) ? true : false;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	Data data[2001];
	int midpoint = 0;
	int tailpoint = 0;

	for (int i = 0; i < files.size(); i++)
	{
		for (int j = 0; j < files[i].size(); j++)
		{
			if ('0' <= files[i][j] && files[i][j] <= '9')
			{
				midpoint = j;
				break;
			}
		}
		
		for (int j = midpoint; j < files[i].size(); j++)
		{
			if ('0' > files[i][j] || files[i][j] > '9')
			{
				tailpoint = j;
				break;
			}

			if (j == files[i].size() -1)
				tailpoint = j+1;
		}

		data[i].num = i;
		data[i].head = files[i].substr(0, midpoint);
		transform(data[i].head.begin(), data[i].head.end(), data[i].head.begin(), ::toupper);
		data[i].mid = atoi(files[i].substr(midpoint, tailpoint - midpoint).c_str());
	}


	stable_sort(data, data + files.size() , com_by_mid);
	stable_sort(data, data+files.size(), com_by_head);



	for (int i = 0; i < files.size(); i++)
	{
		answer.push_back(files[data[i].num]);
	}


	return answer;
}

int main()
{
	vector<string> input;

	input.push_back("b3");
	input.push_back("b2");
	input.push_back("b4");
	input.push_back("b1");
	input.push_back("b5");

	vector<string> ans = solution(input);

	
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " " << ans[i].size() << endl;
	}
	
}