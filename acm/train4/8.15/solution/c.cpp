#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 300
#define MAX_L 16
#define INF 999999999

int N, M, L, S, T;
int jiro[MAX_L + 1], eat[MAX_L + 1];
int g[MAX_N][MAX_N];
int dp[1 << (MAX_L + 1)][MAX_L + 1];

int g_jiro[MAX_L + 1][MAX_L + 1];

void wf(){
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}

void mkJiroGraph(){
  //Jiro Graph
  //  [0]~[L - 1] : Jiro
  //  [L] : Start

  jiro[L] = S;
  eat[L] = 0;

  for(int i = 0; i < L + 1; i++){
    for(int j = 0; j < L + 1; j++){
      g_jiro[i][j] = g[jiro[i]][jiro[j]];
    }
  }
}

void maxJiroDP(){
  //add start node
  L++;

  for(int i = 0; i < (1 << L); i++){
    for(int j = 0; j < L; j++){
      dp[i][j] = INF;
    }
  }

  dp[0][L - 1] = 0;

  for(int pass = 0; pass < (1 << L); pass++){
    for(int now = 0; now < L; now++){
      if(dp[pass][now] == INF) continue;

      for(int next = 0; next < L; next++){
        if(now == next) continue;
        if(g_jiro[now][next] == INF) continue;
        if(pass & (1 << next)) continue;

        int npass = pass | (1 << next);
        int ncost = dp[pass][now];

        ncost += g_jiro[now][next];
        ncost += eat[next];

        dp[npass][next] = min(dp[npass][next], ncost);
      }
    }
  }

  int ans = 0;

  for(int i = 1 << (L - 1); i < (1 << L); i++){
    if(dp[i][L - 1] > T) continue;
    int passJiro = __builtin_popcount(i) - 1; //始点のビット分は引いておく
    ans = max(ans, passJiro);
  }

  cout << ans << endl;
}

void solve(){
  wf();
  mkJiroGraph();
  maxJiroDP();
}

int main(){
  while(cin >> N >> M >> L >> S >> T){
    if(N == 0) break;
    --S;
    //init graph
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        g[i][j] = INF;
      }
    }

    for(int i = 0; i < M; i++){
      int a, b, c;
      cin >> a >> b >> c;
      a--;
      b--;
      g[a][b] = g[b][a] = c;
    }

    for(int i = 0; i < L; i++){
      cin >> jiro[i] >> eat[i];
      jiro[i]--;
    }

    solve();
  }
}
