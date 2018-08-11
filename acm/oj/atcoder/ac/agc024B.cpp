#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200010],cnt[200010],pos[200010];
int main(){
	LL i,j,k;
	cin>>n;
	for(i=0,cnt[n]=1;i<n;i++){
		cin>>a[i];
		pos[a[i]]=i;
		cnt[i]=1;
	}
	for(i=0;i<n;i++){
		j=a[i]-1;
		if(j!=0&&pos[j]<i)cnt[i]=max(cnt[i],cnt[pos[j]]+1);
	}
	for(i=0,k=0;i<n;i++)k=max(k,cnt[i]);
	cout<<n-k<<endl;
	return 0;
}