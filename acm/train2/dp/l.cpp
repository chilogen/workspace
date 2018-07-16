#include <bits/stdc++.h>
using namespace std;
int n,a[202],rig[202],ans=0;
int main(){
	int i,j,k,l,root,cnt;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		rig[i]=i+1;
	}
	rig[n]=1;root=1;cnt=n-1;
	for(i=1;i<n;i++){
		j=root;k=1000000;l=0;
		while(l!=cnt){
			k=min(k,a[j]+a[rig[j]]);
			j=rig[j];
			l++;
		}
		ans+=k;
		j=root;
		while(1){
			if(a[j]+a[rig[j]]==k){
				a[j]=k;
				rig[j]=rig[rig[j]];
				cnt--;
				root=j;
				break;
			}
			j=rig[j];
		}
	}
	cout<<ans<<endl;
	return 0;
}