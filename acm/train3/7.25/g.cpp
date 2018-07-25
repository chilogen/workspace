#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,c;
LL a[310][310];
bool check1(LL x){
	LL i,k=(a[x][0]-1)/c;
	for(i=0;i<c;i++)
		if((a[x][i]-1)/c!=k)return false;
	return true;
}
bool check2(LL x){
	LL i,k=(a[0][x]-1)%c;
	for(i=0;i<n;i++)
		if((a[i][x]-1)%c!=k)return false;
	return true;
}
LL line(){
	LL i,j=0,k;
	for(i=0;i<n;i++){
		k=(a[i][0]-1)/c;
		if(k!=i){
			swap(a[k][0],a[i][0]);
			j++;
			i--;
		}
	}
	return j;
}
LL row(){
	LL i,j=0,k;
	for(i=0;i<c;i++){
		k=(a[0][i]-1)%c;
		if(k!=i){
			swap(a[0][i],a[0][k]);
			j++;
			i--;
		}
	}
	return j;
}
int main(){
	LL i,j,k;
	cin>>n>>c;
	for(i=0;i<n;i++)for(j=0;j<c;j++)cin>>a[i][j];
	for(i=0;i<n;i++){
		if(!check1(i)){
			cout<<"*\n";
			return 0;
		}
	}
	for(i=0;i<c;i++){
		if(!check2(i)){
			cout<<"*\n";
			return 0;
		}
	}
	j=line();k=row();
	cout<<j+k<<endl;
	return 0;
}