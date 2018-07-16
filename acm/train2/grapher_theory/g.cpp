#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
char m[maxn][maxn];
int n,nex[maxn],fro[maxn];
int main(){
	int i,j,k=maxn-1,l;
	ios::sync_with_stdio(false);
	cin>>n;
	memset(nex,-1,sizeof(nex));
	memset(fro,-1,sizeof(fro));
	for(i=0;i<n;i++)	cin>>m[i];
	nex[k]=0;fro[k]=0;
	nex[0]=k;fro[0]=k;
	for(i=1,j=0;i<n;i++){
		l=nex[k];
		while(l!=k){
			if(m[l][i]=='-')break;
			l=nex[l];
		}
		nex[i]=l;fro[i]=fro[l];
		nex[fro[l]]=i;fro[l]=i;
		j++;
	}
	if(j!=n-1)cout<<"NO\n";
	else{
		cout<<"YES\n";
		l=nex[k];
		while(l!=k){
			cout<<l<<" ";
			l=nex[l];
		}
	}
	return 0;
}