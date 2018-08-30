/*
	Problem: Switch Maze
	Solution by: Kazuhiro Hosaka
	
	O(1.8393^N M)
	3-SAT, simple pruning
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

const int N = 26;
const int LIM_M = 1000;

int decode(char c) {
	return isupper(c) ? ((c - 'A') << 1) : ((c - 'a') << 1 | 1);
}

int M;
char A[3][LIM_M * 3 + 10];

int numClause;
int lens[LIM_M * 8 + 10];
int lits[LIM_M * 8 + 10][3];

void addClause(int *xs) {
	int j;
	sort(xs, xs + 3);
	lens[numClause] = 0;
	for (j = 0; j < 3; ++j) {
		if (j) {
			if (xs[j - 1] == xs[j]) {
				//	duplicate literals
				continue;
			}
			if ((xs[j - 1] ^ 1) == xs[j]) {
				//	tautology
				return;
			}
		}
		lits[numClause][lens[numClause]++] = xs[j];
	}
	++numClause;
}

int is[110];

bool solve(int i) {
	if (i == numClause) {
		return 1;
	}
	int len = 0;
	int xs[3];
	int j;
	for (j = 0; j < lens[i]; ++j) {
		int x = lits[i][j];
		if (~is[x]) {
			if (is[x]) {
				return solve(i + 1);
			}
		} else {
			xs[len++] = x;
		}
	}
	for (j = 0; j < len; ++j) {
		int x = xs[j];
		is[x] = 1;
		is[x ^ 1] = 0;
		if (solve(i + 1)) {
			return 1;
		}
		is[x] = 0;
		is[x ^ 1] = 1;
	}
	for (j = 0; j < len; ++j) {
		int x = xs[j];
		is[x] = is[x ^ 1] = -1;
	}
	return 0;
}

int main() {
	int h, i, j;
	int x;
	
	for (; ~scanf("%d", &M); ) {
		if (M == 0) break;
		for (j = 0; j < 3; ++j) {
			scanf("%s", A[j]);
		}
		numClause = 0;
		for (i = 0; i < M; ++i) {
			int xs[3];
			for (h = 0; h < 1 << 3; ++h) {
				for (j = 0; j < 3; ++j) {
					xs[j] = decode(A[j][i * 3 + 1 + ((h >> j) & 1)]);
				}
				addClause(xs);
			}
		}
		memset(is, ~0, (N * 2) * 4);
		bool res = solve(0);
		if (res) {
			int cnt = 0;
			for (x = 0; x < N; ++x) {
				if (~is[x << 1]) {
					if (is[x << 1 | 1]) {
						++cnt;
					}
				}
			}
			printf("%d", cnt);
			for (x = 0; x < N; ++x) {
				if (~is[x << 1]) {
					if (is[x << 1 | 1]) {
						printf(" %c", 'A' + x);
					}
				}
			}
			puts("");
		} else {
			puts("-1");
		}
	}
	
	return 0;
}

