#include <bits/stdc++.h>
#define reset(a,b) memset(a,b,sizeof(a));
using namespace std;
long long S[1001][1001];
const long long int mod=1e9+7;
int n,k,N,K,T;
void getStiring()
{
	reset(S,0);
	S[0][0]=1;
	for(n=1;n<=1000;n++)	
	{
		S[n][n]=1;
		S[n][1]=1;
	}
	for(n=3;n<=1000;n++)	for(k=2;k<=1000&&k<=1000;k++)
		S[n][k]=(S[n-1][k-1]+k*S[n-1][k]%mod)%mod;
}
int main()
{
	cin>>T;
	getStiring();
	while(T--)
	{
		cin>>N>>K;
		cout<<S[N][K]<<endl;
	}
	return 0;
}