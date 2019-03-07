#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000

/*

*/

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

#include <stack>

using namespace std;

int T;
int N, arr[50005];
int maxi = 0;
string str;
vector<int> point;

void getInput() {
	cin >> str;
}

bool eraseAllSubStr(std::string & mainStr, const std::string & toErase)
{
	bool isLoop = false;
	size_t pos = std::string::npos;

	// Search for the substring in string in a loop untill nothing is found
	while ((pos = mainStr.find(toErase)) != std::string::npos)
	{
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
		isLoop = true;
	}

	return isLoop;
}


int solve() {
	int result = 0;
	bool isExist = 0;

	while (1){
		int loop = 0;
		string beforeStr = str;
		
		isExist = eraseAllSubStr(str, "croak");

		if (isExist) {
			result++;
		}
		else {
			break;
		}
	}

	if (str == "")
		return result;
	else
		return -1;
}


int main() {
	int local = 0;
	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();
		printf("#%d %d\n", tt, solve());
	}

}

