#include <bits/stdc++.h>
using namespace std;

int a[210][210];
int val;
int ans[210][210];

void print(int h,int w){
	int i,j;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(ans[i][j]==0)cout<<"(";
			else cout<<")";
		}
		cout<<endl;
	}
}

int check(int h,int w){
	int i,j,k,t=0;
	for(i=0;i<h&&w%2==0;i++){
		k=0;
		for(j=0;j<w;j++){
			if(a[i][j]!=k)break;
			k=!k;
		}
		if(j==w)t++;
	}
	for(j=0;j<w&&h%2==0;j++){
		k=0;
		for(i=0;i<h;i++){
			if(a[i][j]!=k)break;
			k=!k;
		}
		if(i==h)t++;
	}
	return t;
}

int h,w;

void dfs(int n){
	if(n==h*w){
		int i=check(h,w);
		if(i>val){
			val=i;
			if(i==10)cout<<i;
			memcpy(ans,a,sizeof(a));
		}
		return ;
	}
	int x=n/w,y=n%w;
	a[x][y]=0;
	dfs(n+1);
	a[x][y]=1;
	dfs(n+1);
}

int main(){
	cin>>h;
	cin>>h>>w;
	val=0;
	dfs(0);
	print(h,w);
	cout<<val;
	return 0;
}