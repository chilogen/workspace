#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi; typedef pair<ll, int> pli;
typedef pair<ll, ll> pll; typedef pair<ll, pi> plp;
typedef tuple<int, int, int> ti; typedef tuple<ll, int, int> tli;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;


const int MAX_N = 1e5 + 100;

string G;
char P[MAX_N], S[MAX_N];
int pN, sN;
bool Good[222];
int main() {
	cin >> G;
	for(char c : G) Good[c] = true;
	scanf("%s", P); pN = strlen(P);
	int ix = -1;
	for(int i=0; i<pN; i++) if(P[i] == '*') ix = i;

	int Q; cin >> Q;
	while(Q--) {
		scanf("%s", S);
		sN = strlen(S);
		bool isCan = true;
		if(ix == -1) {
			if(pN != sN) isCan = false;
			else {
				for(int i=0; i<pN; i++) {
					if(P[i] == '?') {
						if(Good[S[i]] == false) {
							isCan = false;
							break;
						}
					} else if(S[i] != P[i]) {
						isCan = false;
						break;
					}
				}
			}
		} else {
			if(pN-1 > sN) isCan = false;
			else {
				int l = 0;
				for(int i=0; i<ix; i++) {
					if(P[i] == '?') {
						if(Good[S[i]] == false) {
							isCan = false;
							break;
						}
					} else if(S[i] != P[i]) {
						isCan = false;
						break;
					}
					l++;
				}
				int r = sN-1;
				for(int i=pN-1; i>ix; i--) {
					if(P[i] == '?') {
						if(Good[S[r]] == false) {
							isCan = false;
							break;
						}
					} else if(S[r] != P[i]) {
						isCan = false;
						break;
					}
					r--;
				}
				for(int i=l; i<=r; i++) {
					if(Good[S[i]] == true) {
						isCan = false;
						break;
					}
				}
			}
		}
//		printf("%d -> %d\n", Q, isCan);
		puts(isCan?"YES":"NO");
	}
	return 0;
}