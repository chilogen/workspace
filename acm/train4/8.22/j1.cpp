#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;

LL a[maxn],b[maxn],n;


//计算小于等于x的个数
LL lessthan(LL x){
	LL i,j=n-1,ans=0;
	for(i=0;i<n;i++){
		while(j>=0&&a[i]+b[j]>x)j--;
		if(j<0)return ans;
		ans+=(j+1);
	}
	return ans;
}

//二分计算第k个数
LL kth(LL k){
	LL l=0,r=2e9+10,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(lessthan(mid)>=k)r=mid;
		else l=mid+1;
	}
	return l;
}

//vector<LL>ans;
LL ans[5*maxn],cnt=0;

void add(){
	LL L=n*(n-1)/2+1,R=n*(n+1)/2;
	LL mi=kth(L),ma=kth(R);
	LL i,j,k,l,r,*it;

	//将大于最左端点的值，小于最右端点的值加入答案，例如样例2:把大于7小于9的8加入答案
	l=mi+1;r=ma-1;

	for(i=0;i<n;i++){
		j=l-a[i];
		it=lower_bound(b,b+n,j);
		k=it-b;
		for(j=k;j<n;j++)
			if(a[i]+b[j]>r)break;
			//else ans.push_back(a[i]+b[j]);
			else ans[cnt++]=a[i]+b[j];
	}

	//计算小于等于左端点值，大于右端点值减一的位置，即可得出答案里有几个最小值，几个最大值，相当于lower_bound
	k=lessthan(mi);j=lessthan(ma-1);
	
	/*
	for(i=L;i<=k;i++)ans.push_back(mi);
	for(i=j;i<R;i++)ans.push_back(ma);
	sort(ans.begin(),ans.end());
	*/

	for(i=L;i<=k;i++)ans[cnt++]=mi;
	for(i=j;i<R;i++)ans[cnt++]=ma;
	sort(ans,ans+cnt);
}

void solve(){
	LL i;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++)cin>>b[i];
	sort(a,a+n);sort(b,b+n);
	add();
	for(i=0;i<n;i++)cout<<ans[i]<<" ";
}

int main(){
	solve();
	return 0;
}
