#include <bits/stdc++.h>
using namespace std;
int t,k,s[50010],a[50010],vis[50010];
inline int lowbit(int x){return x&-x;}
inline void change(int x,int v){
	while(x<=k){
		a[x]+=v;
		x+=lowbit(x);
	}
}
inline int query(int x){
	int sum=0;
	while(x>0){
		sum+=a[x];
		x-=lowbit(x);
	}
	return sum;
}
int main(){
	int i,j,l,r,m;
	cin>>t;
	while(t--){
		cin>>k;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=k;i++){
			cin>>s[i];
			change(i,1);
		}
		for(i=1;i<=k;i++){
			l=0,r=k+1;
			while(r>=l){
				m=(l+r)>>1;
				j=query(m);
				if(j==s[i]+1){
					if(vis[m]){
						r=m;
						continue;
					}
					if(i!=k) cout<<m<<" ";
					else cout<<m<<endl;
					vis[m]=1;
					change(m,-1);
					break;
				}
				if((j<s[i]+1&&l==m)||(j>s[i]+1&&r==m))	break;
				if(j<s[i]+1) l=m;
				else r=m;
			}
		}
	}
	return 0;
}