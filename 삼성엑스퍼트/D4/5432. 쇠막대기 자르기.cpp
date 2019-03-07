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

int N, M, Q;
int T;
string str;

void getInput() {
	cin >> str;
}

int solve() {
	int total = 0;
	int lastDepth = 0;
	int depth = -1;

	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '(':
			if (i != 0 && str[i-1] == ')') {
				total += lastDepth - (depth + 1);
			}
			depth++;

			break;
		case ')':
			if (i != 0 && str[i - 1] == '(') {
				total += depth;
				lastDepth = depth;
			}
			depth--;
			break;
		}


//		printf("[%d]d : %d , t : %d\n", i, depth, total);
	}
	total += lastDepth - (depth + 1);
//	total += lastDepth;

//	printf("[f]d : %d , t : %d\n", depth, total);
	return total;
}

int main() {
	int local = 0;
	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();
		printf("#%d %d\n", tt, solve());
	}

}

