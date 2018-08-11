#include <bits/stdc++.h>
using namespace std;

class RedDragonInn{
public:
	int maxGold(int N, int X){
		int ans=0;
		ans=2*(X*N+(N-1))+1;
		return ans;
	}
	void solve(){
		cout<<maxGold(42,1234)<<endl;
	}
}a;
int main(){
	a.solve();
	return 0;
}