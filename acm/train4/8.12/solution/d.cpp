#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "galaxy-center"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

const int maxn = 36;
long long p3[maxn];

void precalc() {
  p3[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p3[i] = p3[i - 1] * 3;
  }
}

string s[2];
char tmp[100];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s[0] = tmp;
  scanf("%s", tmp);
  s[1] = tmp;
  return true;
}

void getCoords(const string &s, long long &x, int &d) {
  x = 0;
  d = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == 's') {
      x++;
      if (x == p3[d]) {
        x = 0;
      }
    } else if (s[i] == 'a') {
      if (x == 0) {
        x = p3[d];
      }
      x--;
    } else if (s[i] == 'c') {
      x *= 3;
      d++;
    } else if (s[i] == 'g') {
      assert(!(x % 3));
      x /= 3;
      d--;
    } else {
      assert(false);
    }
  }
}

string p[2];
string ans;

string rev(string s) {
  reverse(s.begin(), s.end());
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == 'a') {
      s[i] = 's';
    } else if (s[i] == 's') {
      s[i] = 'a';
    } else if (s[i] == 'c') {
      s[i] = 'g';
    } else if (s[i] == 'g') {
      s[i] = 'c';
    } else {
      assert(false);
    }
  }
  return s;
}

void solve() {
  ans = rev(s[0]) + s[1];
  long long x[2];
  int d[2];
  getCoords(s[0], x[0], d[0]);
  getCoords(s[1], x[1], d[1]);
  p[0].clear();
  p[1].clear();
  while (d[0] != d[1] || x[0] != x[1]) {
    if (d[0] == d[1]) {
      if (sz(p[0]) + (x[1] + p3[d[0]] - x[0]) % p3[d[0]] + sz(p[1]) < sz(ans)) {
        ans = p[0] + string((x[1] + p3[d[0]] - x[0]) % p3[d[0]], 's') + rev(p[1]);
      }
      if (sz(p[0]) + (x[0] + p3[d[0]] - x[1]) % p3[d[0]] + sz(p[1]) < sz(ans)) {
        ans = p[0] + string((x[0] + p3[d[0]] - x[1]) % p3[d[0]], 'a') + rev(p[1]);
      }
    }
    int t = (d[0] > d[1] ? 0 : 1);
    if (x[t] % 3 == 1) {
      x[t]--;
      p[t] += 'a';
    } else if (x[t] % 3 == 2) {
      x[t]++;
      if (x[t] == p3[d[t]]) {
        x[t] = 0;
      }
      p[t] += 's';
    }
    assert(!(x[t] % 3));
    x[t] /= 3;
    d[t]--;
    p[t] += 'g';
  }
  if (sz(p[0]) + sz(p[1]) < sz(ans)) {
    ans = p[0] + rev(p[1]);
  }
  printf("%s\n", ans.c_str());
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
