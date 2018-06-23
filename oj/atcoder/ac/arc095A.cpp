#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,b[200010];
struct node{
	LL v,ind;
}x[200010];
bool cmp(node a,node b){
	return a.v<b.v;
}
int main(){
	LL i,j,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x[i].v;
		x[i].ind=i;
	}
	sort(x,x+n,cmp);
	k=(n-1)/2;
	for(i=0;i<n;i++){
		j=x[i].ind;
		if(i>k)b[j]=x[k].v;
		else b[j]=x[k+1].v;
	}
	for(i=0;i<n;i++)cout<<b[i]<<endl;
	return 0;
}