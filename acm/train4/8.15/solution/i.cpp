#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;

typedef long double ld;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

ld A[333][333], B[333];

void gauss(int N) {
  REP(i,N) {
    int pivot=i;
    FOR(j,i+1,N) if (abs(A[pivot][i]) < abs(A[j][i])) pivot=j;
    REP(j,N) swap(A[i][j],A[pivot][j]);
    swap(B[i],B[pivot]);

    FOR(k,i+1,N) {
      ld d=A[k][i]/A[i][i];
      FOR(j,i,N) A[k][j]-=d*A[i][j];
      B[k]-=d*B[i];
    }

    ld u=A[i][i];
    REP(j,N) A[i][j]/=u;
    B[i]/=u;
  }
  for (int i=N-1; i>=0; --i) FOR(j,i+1,N) B[i]-=A[i][j]*B[j];
}


int H, W;
char s[6][6], t[6][6];
typedef vector<int> V;

map<V, int> mp;
V v;
void dfs(int y, int x) {
  if (x == W) {
    int n = SZ(mp);
    mp[v] = n;
    return;
  }
  FOREQ(iy, 0, y) {
    v.push_back(iy);
    dfs(iy, x+1);
    v.pop_back();
  }
}

char r[6][6];
V maximal_part() {
  V u(W);
  int prev = 0;
  for (int j = W-1; j >= 0; --j) {
    int curr = H;
    for (int i = H-1; i >= 0; --i) {
      if (r[i][j] != t[i][j]) break;
      curr = i;
    }
    curr = max(curr, prev);
    u[j] = curr;
    prev = curr;
  }
  return u;
}

double solve() {
  // build index
  mp.clear();
  dfs(H, 0);
  int perm[SZ(mp)];
  REP(i, SZ(mp)) perm[i] = i;
  random_shuffle(perm, perm+SZ(mp));
  int n = 0;
  FORIT(it, mp) it->second = perm[n++];

  int goal = mp[V(W, 0)];

  // make transition matrix
  MEMSET(A, 0);
  MEMSET(B, 0);
  FORIT(it, mp) {
    V w = it->first;
    int wid = it->second;
    A[wid][wid] = 1.0;

    if (wid == goal) {
      // goal state is special
      continue;
    }

    string colors = "BW";
    REP(i0, H) REP(j0, W) REP(k0, 2) {
      REP(i, H) REP(j, W) r[i][j] = (i >= w[j]) ? t[i][j] : 'x';
      REP(i, H) REP(j, W) if (i <= i0 && j <= j0) r[i][j] = colors[k0];

      V u = maximal_part();

      // w -> u
      ld proba  = 1.0 / (H*W*SZ(colors));
      ld weight = (i0+1) * (j0+1);
      int uid = mp[u];

      A[wid][uid] -= proba;
      B[wid] += proba * weight;
    }
  }

  // solve equations
  gauss(SZ(mp));

  // output solution
  REP(i, H) REP(j, W) r[i][j] = s[i][j];
  int init = mp[maximal_part()];
  return B[init];
}

#include <ctime>
int main(int argc, char** argv) {
  srand(time(NULL));
  while (cin >> H >> W) {
    if (H == 0) exit(0);
    REP(i, H) cin >> s[i];
    REP(i, H) cin >> t[i];

    if (argc >= 2) {
      double lo = 1e300, hi = 0;
      REP(iter, 50) {
        double res = solve();
        lo = min(lo, res);
        hi = max(hi, res);
      }
      cerr << "relative error = " << (hi-lo)/lo << endl;
    }

    printf("%.10f\n", solve());
  }
}
