#include <cassert>
#include <cstdio>

int main () {
  int n;
  assert (scanf ("%d", &n) == 1);

  int ans = (int)1e9;
  for (int d1 = 0; 6 * d1 - 18 < ans; d1++)
    for (int d2 = d1 - 2; d2 <= d1 + 2; d2++)
      for (int d3 = d2 - 2; d3 <= d2 + 2; d3++)
        for (int d4 = d3 - 2; d4 <= d3 + 2; d4++) {
          if (d2 < 0 || d3 < 0 || d4 < 0)
            continue;
          if (d1 + d2 == 0 || d2 + d3 == 0 || d3 + d4 == 0)
            continue;
          int x = d1 + d2 - d4;
          int y = d2 + d3;
          if (x < 0)
            continue;
          if (y < x)
            continue;
          int res = d1 + d2 + d3 + d4 + y;
          long long area = (long long)(d1 + d2 - 1) * (d2 + d3 - 1);
          area -= (long long)(d2) * (d2 - 1) / 2;
          area -= (long long)(x) * (x - 1) / 2;
          if (area >= n && res < ans)
            ans = res;
        }
  printf ("%d\n", ans);

  return 0;
}

