#include <iostream>
#include <complex>
#include <vector>
#include <cstring>
using namespace std;

#define EPS (1e-8)
#define MAX_N 8

/* -------------------スパソ始------------------- */
typedef complex<double> P;

struct L : public vector<P>{
  L(const P &a, const P &b){
    push_back(a);
    push_back(b);
  }
};

double cross(const P& a, const P& b){
  return imag(conj(a) * b);
}

double dot(const P& a, const P& b){
  return real(conj(a) * b);
}

P projection(const L &l, const P &p){
  double tmp = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + tmp * (l[0] - l[1]);
}

P reflection(const L &l, const P &p){
  return p + 2.0 * (projection(l, p) - p);
}
/* -------------------スパソ終------------------- */

int N;
P start;
P t[MAX_N + 2];
P unit[MAX_N + 2]; //各辺の単位ベクトル(反時計まわり方向)

//for rec
int order[MAX_N + 2];
bool used[MAX_N + 2];

P getVec(int n, P p){
  for(int i = n - 1; i >= 0; i--){
    int idx = order[i];
    P a = t[idx];
    P b = t[(idx + 1) % N];
    p = reflection(L(a, b), p);
  }
  return p - start;
}

int check(){
  int idx = order[0];
  P left = (t[(idx + 1) % N] - start) - unit[idx] * EPS;
  P right = (t[idx] - start) + unit[idx] * EPS;

  for(int i = 1; i < N; i++){
    idx = order[i];

    P a = t[(idx + 1) % N] - unit[idx] * EPS;
    P b = t[idx] + unit[idx] * EPS;

    P nextLeft = getVec(i, i % 2 == 1 ? b : a);
    P nextRight = getVec(i, i % 2 == 1 ? a : b);

    if(cross(nextLeft, left) < 0) nextLeft = left;
    if(cross(nextRight, right) > 0) nextRight = right;
    if(cross(nextLeft, nextRight) > 0) return 0;

    left = nextLeft;
    right = nextRight;
  }

  return 1;
}

int rec(int idx){
  if(idx == N){
    return check();
  }

  int res = 0;

  for(int i = 0; i < N; i++){
    if(used[i]) continue;

    used[i] = true;
    order[idx] = i;
    res += rec(idx + 1);
    used[i] = false;
  }
  return res;
}

int main(){
  while(cin >> N){
    if(N == 0) break;

    cin >> start.real() >> start.imag();
    for(int i = 0; i < N; i++){
      cin >> t[i].real() >> t[i].imag();
    }

    for(int i = 0; i < N; i++){
      P seg = t[(i + 1) % N] - t[i];
      unit[i] = seg / abs(seg);
    }

    memset(used, 0, sizeof(used));
    cout << rec(0) << endl;
  }
}
