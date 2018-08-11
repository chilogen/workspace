#include <bits/stdc++.h>
using namespace std;
int num[1000010],n[1000010][11]={0};
int f(int x){
	int ans=1,i;
	while(x){
		i=x%10;
		if(i)ans*=i;
		x=x/10;
	}
	return ans;
}
int g(int x){
	if(x<10)	return x;
	else return g(f(x));
}
int main(){
	int i,j,k,l,r,q;
	cin>>q;
	for(i=1;i<=1000000;i++){
		num[i]=g(i);
		for(j=1;j<10;j++){
			if(j==num[i]) n[i][j]=n[i-1][j]+1;
			else n[i][j]=n[i-1][j];
		}
	}
	while(q--){
		scanf("%d%d%d",&l,&r,&k);
		cout<<n[r][k]-n[l-1][k]<<endl;
	}
	return 0;

}