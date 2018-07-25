#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct tape{
	LL size;
	LL v[15];
}in,out;
tape flode(tape x,LL pos){
	LL a[70];
	LL i,j,k;
	k=50;i=pos;j=pos+1;
	while(i>=0&&j<x.size){
		a[k]=x.v[i]+x.v[j];
		k--;i--;j++;
	}
	while(i>=0){
		a[k]=x.v[i];
		k--;i--;
	}
	while(j<x.size){
		a[k]=x.v[j];
		k--;j++;
	}
	tape ans;
	ans.size=(50-k);
	memcpy(ans.v,a+k+1,sizeof(LL)*15);
	return ans;
}
bool equ(tape a,tape b){
	if(a.size!=b.size)return false;
	LL i;
	for(i=0;i<a.size;i++)if(a.v[i]!=b.v[i])return false;
	return true;
}
bool dfs(tape x){
	tape tmp;
	LL i;
	if(equ(x,out))return true;
	for(i=0;i<x.size-1;i++){
		tmp=flode(x,i);
		if(dfs(tmp))return true;
	}
	return false;
}
int main(){
	LL i,j;
	LL a[15];
	cin>>in.size;
	for(i=0;i<in.size;i++)cin>>in.v[i];
	cin>>out.size;
	for(i=0;i<out.size;i++)cin>>out.v[i];
	if(dfs(in)){cout<<"S";return 0;}
	for(i=0,j=in.size-1;j>=0;j--,i++)a[i]=in.v[j];
	memcpy(in.v,a,sizeof(a));
	if(dfs(in))cout<<"S";
	else cout<<"N";
	return 0;
}