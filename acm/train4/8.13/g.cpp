#include <bits/stdc++.h>
using namespace std;
int t,n,k,l;
int vis[1010],a[1010];
int check(int x){
	memset(vis,0,sizeof(vis));
	int i,j,m,ans=0;
	for(i=0;i<l;i++){
		if(x&(1<<i)){
			for(j=1;a[i]*j<=n;j++){
				if(!vis[a[i]*j])ans++;
				else ans--;
				vis[a[i]*j]=!vis[a[i]*j];
			}
		}
	}
	for(i=l;i<k;i++){
		m=0;
		for(j=1;j*a[i]<=n;j++)
			if(vis[j*a[i]])m--;
			else m++;
		ans+=max(0,m);
	}
	return ans;
}
int main(){
	int i,j,kase=1;
	cin>>t;
	while(t--){
		cout<<"Case #"<<kase++<<": ";
		cin>>n>>k;
		for(i=0;i<k;i++)cin>>a[i];
		sort(a,a+k);
		for(i=0;i<k;i++)if(a[i]>31)break;
		l=i;
		for(i=0,j=0;i<(1<<l);i++)
			j=max(j,check(i));
		cout<<j<<endl;
	}
	return 0;
}