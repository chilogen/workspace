#include <iostream>
#include <cstring>
using namespace std;
int a[210][210];
int val;
int ans[210][210];

void print(int h,int w){
	int i,j;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(a[i][j]==0)cout<<"(";
			else cout<<")";
		}
		cout<<endl;
	}
}

void solve(int h,int w){
	int i,j,k,l,m;
	val=0;
	if(h%2!=0||w%2!=0){
		if(h%2==0){
			for(j=0;j<w;j++)for(i=0;i<h;i++)a[i][j]=i%2;
		}
		else if(w%2==0){
			for(i=0;i<h;i++)for(j=0;j<w;j++)a[i][j]=j%2;
		}
	}
	else if(h%2==0&&w%2==0){
		if(h<w){
			for(j=0;j<w;j++){
				a[0][j]=0;
				a[h-1][j]=1;
			}
			l=w/2;k=0;
			for(i=1;i<h-1;i++){
				k=!k;
				for(j=0;j<l;j++)a[i][j]=k;
				for(;j<w;j++)a[i][j]=!k;/*
				if(i%2==0){
					m=0; 
					for(j=1;j<l;j++){
						a[i][j]=m;
						m=!m;
					}
				}*/
			}
		}
		else{
			for(i=0;i<h;i++){
				a[i][0]=0;
				a[i][w-1]=1;
			}
			l=h/2;k=0;
			for(j=1;j<w-1;j++){
				k=!k;
				for(i=0;i<l;i++)a[i][j]=k;
				for(;i<h;i++)a[i][j]=!k;/*
				if(j%2==0){
					m=0;
					for(i=1;i<l;i++){
						a[i][j]=m;
						m=!m;
					}
				}*/
			}
		}
	}
	print(h,w);
}

int main(){
	int t,h,w;
	cin>>t;
	while(t--){
		cin>>h>>w;
		solve(h,w);
	}
	return 0;
}