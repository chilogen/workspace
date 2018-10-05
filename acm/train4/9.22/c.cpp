#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL cnt[5][5]={{0 , 0 , 0 , 2 , 4}, \
			  {0 , 0 , 4 , 8 , 10}, \
			  {0 , 4 , 8 , 12, 14}, \
			  {2 , 8 , 12, 16, 20}, \
			  {4 , 10 , 14, 20, 24}};

LL solve(LL x,LL y){
	LL tans,a,b;
	tans=x*(y/6)*6; 
	a=x;b=y%6;
	tans+=(b*(x/6)*6);
	a=a%6;
	if(a==0||b==0)return tans;
	return tans+cnt[a-1][b-1];
}

int main(){
	cin>>n>>m;
	cout<<max(solve(n,m),solve(m,n))<<endl;
	return 0;
}