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
#define TASK "ibm1403"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);


void precalc() {
}

const int maxn = 1e5 + 5;
int n;
string s;
char tmp[maxn + 1];

int read() {
  if (!fgets(tmp, maxn, stdin)) {
    return false;
  }
  s = tmp;
  n = sz(s) - 1;
  return true;
}

const int sigma = 200;
set<int> st[sigma];

string row;

void solve() {
  for (int i = 0; i < sigma; i++) {
    st[i].clear();
  }
  for (int i = 0; i < n; i++) {
    st[(int) s[i]].insert(i);
  }
  int pos = 0;
  long long ans = 0;
  while (fgets(tmp, maxn, stdin)) {
    row = tmp;
    int t = 0;
    for (int i = 0; i + 1 < sz(row); i++) {
      if (row[i] == ' ') {
        continue;
      }
      const auto &st = ::st[(int) row[i]];
      assert(!st.empty());
      int x = (pos + i) % n;
      auto it = st.lower_bound(x);
      if (it == st.end()) {
        it = st.begin();
      }
      t = max(t, (*it + n - x) % n);
    }
    ans += t + 1;
    pos = (pos + t + 1) % n;
  }
  printf("%lld\n", ans);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}
