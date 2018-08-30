#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  double l, r;
  double pd = 0;
  while (scanf("%lf%lf", &l, &r) == 2) {
    if (l < -0.5) break;
    double d = r - l;
    double ctl = d * 2 + (d - pd) * 5;
    pd = d;

    double ml = 1 - ctl, mr = 1 + ctl;

    if (ml < -1) ml = -1;
    if (ml > 1) ml = 1;
    if (mr < -1) mr = -1;
    if (mr > 1) mr = 1;

    printf("%.4lf %.4lf\n", ml, mr);
    fflush(stdout);
  }
  return 0;
}
