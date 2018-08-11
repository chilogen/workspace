#include <bits/stdc++.h>
using namespace std;
int n,a,b,s[400000];
int main(){
	int nowmax,i,j,k,tmp,remain;
	cin>>n>>a>>b;
	i=0; nowmax=b; tmp=b;	remain=n-b;	a--;
	while(tmp)s[i++]=tmp--;
	while(i<n){
		j=remain-a+1;
		if(j<=0){
			cout<<-1<<endl;
			return 0;
		}
		tmp=nowmax+min(j,b);
		while(tmp-nowmax)s[i++]=tmp--;
		remain-=min(j,b);
		nowmax+=min(j,b);
		a--;
	}
	if(a!=0){
		cout<<-1<<endl;
		return 0;
	}
	for(i=0;i<n;i++)cout<<s[i]<<" ";
	cout<<endl;
	return 0;
}
https://arc091.contest.atcoder.jp/submissions/2229241