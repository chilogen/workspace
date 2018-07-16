#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p,k,n,a[35];
void dfs(LL x,LL &p,LL &q){
	LL a,b;
	if(x==1){
		p=q=1;
		return;
	}
	dfs(x/2,p,q);
	a=p;b=q;
	if(x%2==0)q=a+b;
	else{p=a+b;q=b;}
}
int main(){
	LL i,l,ind,x,y;
	for(i=1,a[0]=1;i<35;i++)a[i]=a[i-1]*2;
	cin>>p;
	while(p--){
		cin>>i>>n;
		l=0;k=n;ind=0;
		while(k>a[l]){
			k-=a[l];
			ind+=a[l];
			l++;
		}
		ind+=k;
		dfs(ind,x,y);
		cout<<i<<" ";
		cout<<x<<"/"<<y<<endl;
	}
	return 0;
}