#include <cstdio>
#include <cstdlib>
#include <cassert>


#define MaxN 105
#define MaxR 30
#define MAXPOS ((MaxR + 5) * (MaxR + 5) * (MaxR + 5) * (MaxR + 5) * 2)

int Q[MAXPOS];
char P[MAXPOS];
short C[MAXPOS];
int qh, qt;

int n;

inline int postonum (int qx, int qy, int kx, int ky, int side) {
  return (((qx * (n + 2) + qy) * (n + 2) + kx) * (n + 2) + ky) * 2 + side;
}

inline void numtopos (int pos, int &qx, int &qy, int &kx, int &ky, int &side) {
  side = pos & 1;
  pos >>= 1;
  ky = pos % (n + 2);
  pos /= n + 2;
  kx = pos % (n + 2);
  pos /= n + 2;
  qy = pos % (n + 2);
  pos /= n + 2;
  qx = pos % (n + 2);
}

inline int isvalid (int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= n;
}

inline void push (int pos, int res) {
  if (P[pos]) return;
  P[pos] = res;
  Q[qt++] = pos;
}

typedef void (*mhf)(int qx, int qy, int kx, int ky, int side);

void iteratequeenmoves (int qx, int qy, int kx, int ky, mhf func) {
      int qnx, qny;
      for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) if (dx || dy) {
          qnx = qx, qny = qy;
          for (int l = 1; l <= n; l++) {
            qnx += dx, qny += dy;
            if (!isvalid (qnx, qny)) break;
            func (qnx, qny, kx, ky, 1);
            if (qnx == kx && qny == ky) break;
          }
        }
}

void iterateknightmoves (int qx, int qy, int kx, int ky, mhf func) {
  for (int dx = -2; dx <= 2; dx++)
    for (int dy = -2; dy <= 2; dy++)
      if (abs (dx) + abs (dy) == 3 && isvalid (kx + dx, ky + dy)) {
        func (qx, qy, kx + dx, ky + dy, 0);
      }
}

void iteratemoves (int qx, int qy, int kx, int ky, int side, mhf func) {
  if (!side) {
    iteratequeenmoves (qx, qy, kx, ky, func);
  } else {
    iterateknightmoves (qx, qy, kx, ky, func);
  }
}

int gc, gres, gbest;

void countmove (int, int, int, int, int) {
  ++gc;
}

void pusheverything (int qx, int qy, int kx, int ky, int side) {
  push (postonum (qx, qy, kx, ky, !side), gres);
}

void pushcount (int qx, int qy, int kx, int ky, int side) {
  int pos = postonum (qx, qy, kx, ky, !side);
  if (!--C[pos]) push (pos, gres);
}


void isbetter (int qx, int qy, int kx, int ky, int side) {
  int pos = postonum (qx, qy, kx, ky, side);
  if (0 < P[pos] && P[pos] < gres) gbest = pos;
}


void initretro () {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      push (postonum (i, j, i, j, 0), -1);
      push (postonum (i, j, i, j, 1), 1);
    }
  for (int qx = 1; qx <= n; qx++)
    for (int qy = 1; qy <= n; qy++)
      for (int kx = 1; kx <= n; kx++)
        for (int ky = 1; ky <= n; ky++)
          for (int side = 0; side <= 1; side++) {
            gc = 0;
            iteratemoves (qx, qy, kx, ky, side, countmove);
            C[postonum (qx, qy, kx, ky, side)] = gc;
          }
}


void doretro () {
  while (qh < qt) {
    int v = Q[qh++];
    int qx, qy, kx, ky, side;
    numtopos (v, qx, qy, kx, ky, side);
    gres = P[v];
    if (gres < 0) --gres; else ++gres;
    //fprintf (stderr, "%d %d %d %d %d %d %d %d %d\n", qh, qt, v, qx, qy, kx, ky, side, gres);
    if (gres & 1) {
      iteratemoves (qx, qy, kx, ky, !side, pushcount);
    } else {
      iteratemoves (qx, qy, kx, ky, !side, pusheverything);
    }
  }
  //fprintf (stderr, "gres = %d\n", gres);
}

int main () {
  int qx, qy, kx, ky;
  assert (scanf ("%d", &n) == 1);
  if (n <= 30) {
    initretro ();
    doretro ();
  }
  //fprintf (stderr, "Done\n");
  while (1) {
  assert (scanf ("%d%d%d%d", &qx, &qy, &kx, &ky) == 4);
  if (!qx && !qy && !kx && !ky) break;
  if (n > 30) {
  if (kx < n / 2 && qx < kx) qx = (int)1e9;
  if (kx > n / 2 && qx > kx) qx = -(int)1e9;
  }
  
  
  while (1) {
    if (qx == kx || qy == ky || kx - qx == ky - qy || kx - qx == qy - ky) {
      printf ("%d %d\n", kx, ky); fflush (stdout);
      break;
    }
    
    if (n <= 30) {
    int side;
    gres = P[postonum (qx, qy, kx, ky, 0)];
    //fprintf (stderr, "%d %d %d %d %d\n", qx, qy, kx, ky, gres);
    gbest = -1;
    iteratequeenmoves (qx, qy, kx, ky, isbetter);
    assert (gbest >= 0);
    numtopos (gbest, qx, qy, kx, ky, side);
    } else {
    if (abs (kx - qx) < 4) {
      qy = ky;
    } else if (abs (kx - qx) > 4 || abs (ky - qy) > 2) {
      qx = (qx < kx) ? kx - 3 : kx + 3;
    } else {
      qx = (qx < kx) ? qx + abs (ky - qy) : qx - abs (ky - qy);
      qy = ky;
    }
    
    }
    

    printf ("%d %d\n", qx, qy); fflush (stdout);
    assert (scanf ("%d%d", &kx, &ky) == 2);
    if (!kx && !ky) goto skip;
  }
  assert (scanf ("%d%d", &kx, &ky) == 2);
  assert (!kx && !ky);
  skip:;
  }
}
