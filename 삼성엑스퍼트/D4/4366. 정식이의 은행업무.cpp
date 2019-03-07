#define _CRT_SECURE_NO_WARNINGS
#define null NULL
#define INF 987654321
#define SHIFT 15
#define MAN 10000
#define BAKMAN 1000001
#define MOD 1000000007

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <string.h>

using namespace std;

int N, M;

string A, B;


void getInput() {
	cin >> A >> B;
}

unsigned long long inverter(string a, int jinsu) {
	unsigned long long temp = 0;
	long long counter = 1;
	int i = a.length()-1;

	while (i >= 0) {
		temp += (a[i]-'0')*counter ;

		counter *= jinsu;
		i--;
	}
	
	return temp;
}

bool possible(unsigned long long aa) {
	int counter = 1;
	for (int i = 0; i < B.length(); i++) {
		string temp = B;

		switch (B[i]) {
		case '0':
			temp[i] = '1';
			if (inverter(temp, 3) == aa)
				return true;
			temp[i] = '2';
			if (inverter(temp, 3) == aa)
				return true;
			break;
		case '1':
			temp[i] = '2';
			if (inverter(temp, 3) == aa)
				return true;
			temp[i] = '0';
			if (inverter(temp, 3) == aa)
				return true;
			break;
		case '2':
			temp[i] = '1';
			if (inverter(temp, 3) == aa)
				return true;
			temp[i] = '0';
			if (inverter(temp, 3) == aa)
				return true;
			break;
		}

		counter *= 3;
	}

	return false;
}


long long solve() {
	unsigned long long answer = 0;
	unsigned long long a, b;
	unsigned long long gap;

	a = inverter(A, 2);
	b = inverter(B, 3);

	for (int i = 0; i < A.length(); i++) {
		string temp = A;
		unsigned long long val = 0;
		if (A[i] == '0')
			temp[i] = '1';
		else
			temp[i] = '0';

		val = inverter(temp, 2);

		if (possible(val)) {
			answer = inverter(temp, 2);
			break;
		}
	}

	return answer;
}

int main() {
	int T;

	cin >> T;

	for (int tt = 1; tt <= T; tt++) {
		getInput();

		printf("#%d %lld\n", tt, solve());
	}
}