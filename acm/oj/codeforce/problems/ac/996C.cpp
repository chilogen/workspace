#include <bits/stdc++.h>
using namespace std;
int n,a[110],p[2][110];
void update(){
	int i;
	memset(p,-1,sizeof(p));
	for(i=0;i<n;i++){
		if(p[0][a[i]]==-1)p[0][a[i]]=i;
		else p[1][a[i]]=i;
	}
}
int main(){
	int i,j,k,l,r,ans=0;
	cin>>n;
	n*=2;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=1;i<=n/2;i++){
		update();
		l=p[0][i];r=p[1][i];
		if(r==l+1)continue;
		for(j=l+1,j=0,k=0;j<r;j++){
			if(p[0][a[j]]<l)j++;
			else k++;
		}
		if(j>k){
			for(j=l;j<r-1;j++){
				swap(a[j],a[j+1]);
				ans++;
			}
		}
		else{
			for(j=r;j>l+1;j--){
				swap(a[j],a[j-1]);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}