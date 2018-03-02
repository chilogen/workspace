#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[30],b[30];
int main(){
	LL i,j,k,l,n;
	bool zero=false;
	cin>>k;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(i=17;k!=0&&i>=0;i--){
		if(k>1){
			k-=2;
			a[i]=2;
		}
		else{
			k-=1;
			a[i]=1;
		}
	}
	if(k!=0){
		cout<<-1<<endl;
		return 0;
	}
	if(a[0]!=-1){
		if(a[0]==0){
			b[0]=1;
			zero=true;
		}
		else{
			cout<<-1<<endl;
			return 0;
		}
	}
	for(i=1;i<18;i++){
		if(a[i]==-1)	b[i]=-1;
		if(zero){
			if(a[i]!=1){
				cout<<-1<<endl;
				return 0;
			}
			b[i]=0;
		}
		else{
			if(a[i]==0)	b[i]=1;
			else if(a[i]==1)	b[i]=4;
			else if(a[i]==2)	b[i]=8;
		}
	}
	for(i=0;i<18;i++){
		if(b[i]!=-1)cout<<b[i];
	}
	cout<<endl;
	return 0;
}