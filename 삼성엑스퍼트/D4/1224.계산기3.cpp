#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000
#define BAKMAN 1000000
#define MOD 1000000007
#define FAC9 362880

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <string.h>
#include <unordered_map>
#include <stack>

using namespace std;

int N, M, T;

string str;
stack<int> sik;

void init() {
	;
}

void getInput() {
	cin >> N;
	cin >> str;
}

stack<int> inTopost(string str) {
	int i = 0;
	stack<char> op;

	while (i < str.length()) {
		if ('0' <= str[i] && str[i] <= '9') {
			sik.push(str[i] - '0');
		}
		else {
			switch (str[i]) {
			case '+':
				while (!op.empty() && op.top() == '*') {
					sik.push(-2);
					op.pop();
				}
				op.push('+');
				break;
			case '*':
				op.push('*');
				break;
			case '(':
				op.push(str[i]);
				break;
			case ')':
				while (op.top() != '(') {
					if (op.top() == '+') sik.push(-1);
					else sik.push(-2);
					op.pop();
				}
				op.pop();
				break;
			default:
				cout << "input err" << endl;
			}
		}

		i++;
	}

	while (!op.empty()) {
		if (op.top() == '+') sik.push(-1);
		else sik.push(-2);
		op.pop();
	}

	stack<int> temp;

	while (!sik.empty()) {
		temp.push(sik.top());
		
		sik.pop();
	}

	return temp;
}

int calcPostfix() {
	stack<int> op;
	while (!sik.empty()) {
		int first, second;

		if (sik.top() >= 0) {
			op.push(sik.top());
			sik.pop();
		}
		else {
			second = op.top();
			op.pop();
			first = op.top();
			op.pop();

			if (sik.top() == -1)//+
				op.push(first + second);
			else
				op.push(first*second);

			sik.pop();
		}
	}

	return op.top();
}

long long solve() {
	register long long ans = 0;

	sik = inTopost(str);

	ans = calcPostfix();

	return ans;
}

int main() {
	T = 10;
	init();

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		cout << "#" << tt<< " " <<solve() << endl;
	}
}