#include <bits/stdc++.h>
using namespace std;
int n,m,t,p,d,c,x,y;
int a[64][64];
void fold(){
	int i1,j1,i2,j2,k;
	if(d==1){
		for(j2=c,j1=c-1;j1>=0;j1--,j2++){
			for(i1=i2=0;i1<m;i1++,i2++){
				a[i2][j2]+=a[i1][j1];
			}
		}
		k=max(j2,n);
		for(j2=c,j1=0;j2<k;j2++,j1++){
			for(i1=i2=0;i1<m;i1++,i2++){
				a[i1][j1]=a[i2][j2];
			}
		}
		n=k-c;
		for(j1=n;j1<64;j1++)for(i1=0;i1<m;i1++)a[i1][j1]=0;
	}
	else{
		for(i2=c,i1=c-1;i1>=0;i1--,i2++){
			for(j1=j2=0;j1<n;j1++,j2++){
				a[i2][j2]+=a[i1][j1];
			}
		}
		k=max(m,i2);
		for(i2=c,i1=0;i2<k;i1++,i2++){
			for(j1=j2=0;j1<n;j1++,j2++){
				a[i1][j1]=a[i2][j2];
			}
		}
		m=k-c;
		for(i1=m;i1<64;i1++)for(j1=0;j1<n;j1++)a[i1][j1]=0;
	}
}
int main(){
	int i,j;
	while(1){
		memset(a,0,sizeof(a));
		cin>>n>>m>>t>>p;
		for(i=0;i<m;i++)for(j=0;j<n;j++)a[i][j]=1;
		if(n+m+t+p==0)break;
		for(i=0;i<t;i++){
			cin>>d>>c;
			fold();
		}
		for(i=0;i<p;i++){
			cin>>x>>y;
			cout<<a[y][x]<<endl;
		}/*
		for(i=m;i>=0;i--){
			for(j=0;j<=n;j++)cout<<a[i][j]<<" ";
			cout<<endl;
		}*/
	}
	return 0;
}