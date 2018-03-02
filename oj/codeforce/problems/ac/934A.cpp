#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[60],b[60],ans[60],n,m;
int main(){
	LL i,j,k,l;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
		ans[i]=(LL)-1e19;
	}
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i)	continue;
			for(k=0;k<m;k++){
				l=a[j]*b[k];
				if(l>ans[i])	ans[i]=l;
			}
		}
	}
	for(i=0,j=(LL)1e19;i<n;i++){
		if(ans[i]<j)	j=ans[i];
	}
	cout<<j<<endl;
	return 0;
}