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
#define TASK "safe-land"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);


void precalc() {
}

string s;
char tmp[105];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  return true;
}

const string chs = "NWSE";
int used[4];

void solve() {
  memset(used, 0, sizeof(used));
  for (int i = 0; i < sz(s); i++) {
    int id = find(chs.begin(), chs.end(), s[i]) - chs.begin();
    assert(id < sz(chs));
    used[id] = true;
  }
  int cnt = 0;
  for (int i = 0; i < sz(chs); i++) {
    cnt += used[i];
  }
  assert(cnt < sz(chs));
  if (cnt == 1) {
    printf("X\n");
    return;
  }
  if (cnt == 2) {
    if ((used[0] && used[2]) || (used[1] && used[3])) {
      printf("X\n");
      return;
    }
  }
  for (int i = 0; i < sz(chs); i++) {
    if (!used[i]) {
      printf("%c", chs[i]);
    }
  }
  printf("\n");
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
