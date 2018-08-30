#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;

const int mod = 998244353;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

const int maxn = 1 << 18;

void fft(int * a, int n, bool back = false) {
  static int rev[maxn];
  int logn = 0;
  for (; (1 << logn) < n; logn++);

  rev[0] = 0;
  for (int i = 1, j = -1; i < n; i++) {
    if (!(i & (i - 1))) {
      j++;
    }
    rev[i] = rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j));
  }

  if (back) {
    reverse(a + 1, a + n);
  }

  for (int i = 0; i < n; i++) {
    if (rev[i] < i) {
      swap(a[i], a[rev[i]]);
    }
  }

  for (int i1 = 1; i1 < n; i1 <<= 1) {
    int tomult = power(3, (mod - 1) / (2 * i1));
    for (int i = 0; i < n; i += i1) {
      int cur = 1;
      for (int it = 0; it < i1; i++, it++) {
        int toadd = mult(a[i + i1], cur);
        a[i + i1] = a[i];
        add(a[i], toadd);
        add(a[i + i1], mod - toadd);
        cur = mult(cur, tomult);
      }
    }
  }
  
  if (back) {
    int tomult = inv(n);
    for (int i = 0; i < n; i++) {
      a[i] = mult(a[i], tomult);
    }
  }
}

int invs[maxn];

//x := 1 / y
void inverse(int n0, int * x, int * y) {
  static int fy[maxn];
  x[0] = 1;
  for (int i = 1; i < n0; i <<= 1) {
    for (int j = 0; j < 4 * i; j++) {
      fy[j] = (j < 2 * i) ? y[j] : 0;
      if (j >= i) {
        x[j] = 0;
      }
    }
    fft(fy, 4 * i);
    fft(x, 4 * i);
    for (int j = 0; j < 4 * i; j++) {
      x[j] = (2 * x[j] - ((ll) x[j] * x[j] % mod) * fy[j]) % mod;
      if (x[j] < 0) {
        x[j] += mod;
      }
    }
    fft(x, 4 * i, true);
  }
}

//x := log(y)
void logarithm(int n0, int * x, int * y) {
  static int tmp[maxn];
  inverse(n0, x, y);
  for (int i = 0; i < n0 * 2; i++) {
    if (i < n0 - 1) {
      tmp[i] = mult(y[i + 1], i + 1);
    } else {
      tmp[i] = 0;
    }
    if (i >= n0) {
      x[i] = 0;
    }
  }
  fft(tmp, n0 * 2);
  fft(x, n0 * 2);
  for (int i = 0; i < n0 * 2; i++) {
    x[i] = mult(x[i], tmp[i]);
  }
  fft(x, n0 * 2, true);
  for (int i = n0 - 1; i >= 0; i--) {
    x[i] = mult(x[i - 1], invs[i]);
  }
}

//a := exp(b)
void exponent(int n0, int * a, int * b) {
  static int fb[maxn];
  static int x[maxn], y[maxn];
  a[0] = 1;
  for (int i = 1; i < n0; i <<= 1) {
    for (int j = 0; j < i * 2; j++) {
      y[j] = (j < i) ? a[j] : 0;
    }
    logarithm(i * 2, x, y);
    for (int j = 0; j < 4 * i; j++) {
      fb[j] = !j;
      if (j < 2 * i) {
        add(fb[j], b[j]);
        add(fb[j], mod - x[j]);
      }
      if (j >= i) {
        a[j] = 0;
      }
    }
    fft(a, 4 * i);
    fft(fb, 4 * i);
    for (int j = 0; j < 4 * i; j++) {
      a[j] = mult(a[j], fb[j]);
    }
    fft(a, 4 * i, true);
  }
}

void precalc() {
  for (int i = 1; i < maxn; i++) {
    invs[i] = inv(i);
  }
}

int n, m, k;
int f[maxn], g[maxn];
int lf[maxn], lg[maxn];
int ans[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n + 1; i++) {
    assert(scanf("%d", f + i) == 1);
  }
  for (int i = 0; i < m + 1; i++) {
    assert(scanf("%d", g + i) == 1);
  }
  return true;
}

int tmp[maxn];

void solve() {
  int n0 = 1;
  for (; n0 < k; n0 <<= 1);

  logarithm(n0, lf, f);
  logarithm(n0, lg, g);

  for (int i = 0; i < n0; i++) {
    tmp[i] = mult(mult(lf[i], lg[i]), i);
    if (!(i & 1)) {
      tmp[i] = mult(tmp[i], mod - 1);
    }
  }
  exponent(n0, ans, tmp);

  for (int i = 0; i < k; i++) {
    printf("%d%c", ans[i], " \n"[i == k - 1]);
  }
}

#define PROBLEM "roots"

int main() {
  //assert(freopen(PROBLEM ".in", "r", stdin));
  //assert(freopen(PROBLEM ".out", "w", stdout));
  precalc();

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
