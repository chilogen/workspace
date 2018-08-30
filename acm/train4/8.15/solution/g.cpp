#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const long long INF = 1000000000000000000LL;

int main(){
	int N;
	while(cin >> N && N){
		vector< pair<int,int> > multi;
		vector<int> one;
		if(N == 2){
			int a, b, c; cin >> a >> c >> b >> c;
			cout << abs(a-b) << endl;
			continue;
		}
		for(int i=0;i<N;i++){
			int p, d; cin >> p >> d;
			if(d == 1) one.push_back(p);
			else       multi.push_back(make_pair(p, d));
		}
		sort(one.begin(), one.end());
		sort(multi.begin(), multi.end());
		if(multi.size() > 1){
			multi[0].second--;
			multi.back().second--;
			for(int i=1;i+1<multi.size();i++) multi[i].second -= 2;
		}
		vector< vector<long long> > dp(2, vector<long long>(one.size()+1, INF));
		dp[0][0] = 0;
		for(int i=0;i<multi.size();i++){
			int cur = i%2, next = 1-cur;
			for(int j=0;j<=one.size();j++) dp[next][j] = dp[cur][j];
			for(int j=0;j<one.size();j++){
				long long sum = 0;
				for(int k=0;k<multi[i].second && j+k<one.size();k++){
					sum += abs(multi[i].first - one[j+k]);
					dp[next][j+k+1] = min(dp[next][j+k+1], dp[cur][j]+sum);
				}
			}
		}
		long long res = dp[multi.size()%2][one.size()];
		cout << (res == INF ? -1 : res + multi.back().first - multi[0].first) << endl;
	}
}
