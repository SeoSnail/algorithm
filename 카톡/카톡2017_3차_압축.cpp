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

vector<string> dic;
int dic_num=0;
int cnt = 0;

vector<int> solution(string msg) {
	vector<int> answer;

	char a = 'A';
	dic.push_back("/");
	for (int i = 0; i <= 'Z'-'A'; i++)
	{
		char b = a + i;
		string temp(1, b);
		dic.push_back( temp );
	}

	if (msg.length() == 1)
	{
		answer.push_back(((int)msg.c_str()[0])-'A'+1);

		return answer;
	}
	
	for (int i = 0; i < msg.length(); i++)
	{
		string beforeWord;
		int loopNum = 0;
		int beforeIndex = 0;
		bool isNew = false;

		for (int j = 0; j < msg.length(); j++)
		{
			bool flag = false;
			string now = msg.substr(i, j + 1);

			
			if (j != 0 && i + j > msg.length())
			{
				i += loopNum;
				answer.push_back(beforeIndex);
//				dic.push_back(now);
				break;
			}
			

			for (int k = dic.size() - 1; k >= 0; k--)
			{
				if (dic[k] == now)
				{
					loopNum++;
					beforeWord = now;
					beforeIndex = k;
					flag = true;
					break;
				}
			}

			if (!flag)
			{
				answer.push_back(beforeIndex);
				dic.push_back(now);
				i += loopNum - 1;

//				cout << answer[cnt++] << " " << now << endl;
				
				break;
			}
		}
	}


	return answer;
}

int main()
{
	vector<int> sol = solution("A");

	
	for (int str : sol)
		cout << str << endl;


}

