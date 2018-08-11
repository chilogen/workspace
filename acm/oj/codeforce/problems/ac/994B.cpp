#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
struct kni{
	LL p,c,ind,ans;
}a[100010];
bool cmp1(kni x,kni y){return x.p<y.p;}
bool cmp2(kni x,kni y){return x.ind<y.ind;}
priority_queue<LL,vector<LL>,greater<LL> >q;
int main(){
	LL i,j=0,l,sum=0;
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(i=0;i<n;i++)cin>>a[i].p;
	for(i=0;i<n;i++)cin>>a[i].c;
	if(k==0){
		for(i=0;i<n;i++)cout<<a[i].c<<" ";
		return 0;
	}
	for(i=0;i<n;i++)a[i].ind=i;
	sort(a,a+n,cmp1);
	a[0].ans=a[0].c;
	for(i=1;i<n;i++){
		q.push(a[i-1].c);j++;sum+=a[i-1].c;
		if(j>k){
			l=q.top();q.pop();
			j--;sum-=l;
		}
		a[i].ans=sum+a[i].c;
	}
	sort(a,a+n,cmp2);
	for(i=0;i<n;i++)cout<<a[i].ans<<" ";
	cout<<endl;
	return 0;
}