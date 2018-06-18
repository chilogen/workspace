#include <bits/stdc++.h>
using namespace std;
int v[200020],n,t,id,mx,p[200020],ans;
int main(){
	int i,j,k;
	ios::sync_with_stdio(false);
	cin>>t;
	memset(v,-1,sizeof(v));v[0]=-2;
	while(t--){
		ans=0;
		cin>>n;
		for(i=2;i<2*n+1;i+=2)cin>>v[i];
		v[i]=-3;i++;
		k=i;
		id=mx=0;p[0]=1;
		for(j=1;j<k-2;j++){
			p[j]=mx>j?min(p[2*id-j],mx-j):1;
			while(v[j-p[j]]==v[j+p[j]])p[j]++;
			if(mx<j+p[j]){
				mx=j+p[j];
				id=j;
			}
			ans=max(ans,p[j]-1);
			if(ans>i-j-1)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}