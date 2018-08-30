/*
	Problem: C++11
	Solution by: Kazuhiro Hosaka
	
	O(|S|)
	Recursive descent from the right
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const Int MO = 1000000007;
const int LIM_LEN_S = 100000;

int C;
char S[LIM_LEN_S + 10];

bool eat(char c) {
	if (S[C] == c) {
		--C;
		return 1;
	} else {
		return 0;
	}
}

void spaces();
Int number();
Int equation();
Int factor();

void spaces() {
	for (; eat(' '); );
}
Int number() {
	Int ret = 0;
	Int ten = 1;
	for (; isdigit(S[C]); ) {
		Int tmp = S[C] - '0';
		--C;
		ret += tmp * ten;
		ten *= 10;
	}
	return ret;
}
Int equation() {
	Int ret = factor();
	spaces();
	if (eat('>')) {
		assert(eat('>'));
		spaces();
		Int tmp = equation();
		ret = tmp >> min(ret, 63LL);
	}
	return ret;
}
Int factor() {
	Int ret;
	if (eat('>')) {
		spaces();
		Int tmp = equation();
		spaces();
		assert(eat('<'));
		spaces();
		assert(eat('S'));
		ret = (tmp * tmp) % MO;
	} else {
		ret = number();
	}
	return ret;
}

int main() {
	
	
	for (; gets(S + 1); ) {
		if (!strcmp(S + 1, "#")) break;
		C = strlen(S + 1);
		Int res = equation();
		assert(C == 0);
		printf("%lld\n", res);
	}
	
	return 0;
}


