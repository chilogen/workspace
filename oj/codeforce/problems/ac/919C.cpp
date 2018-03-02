#include <bits/stdc++.h>
using namespace std;
int n,m,k;
char c[2010][2010];
int main(){
	int i,j,l,ans=0;
	cin>>n>>m>>k;
	c[2009][2009]=getchar();
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			c[i][j]=getchar();
		c[2009][2009]=getchar();
	}
	if(k==1){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(c[i][j]=='.')	ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(i=0;i<n;i++){
		l=0;
		for(j=0;j<m;j++){
			if(c[i][j]=='.') l++;
			if(c[i][j]=='*'){
				if(l>=k)	ans=ans+l-k+1;
				l=0;
			}
		}
		if(l>=k)	ans=ans+l-k+1;
	}
	for(j=0;j<m;j++){
		l=0;
		for(i=0;i<n;i++){
			if(c[i][j]=='.') l++;
			if(c[i][j]=='*'){
				if(l>=k)	ans=ans+l-k+1;
				l=0;
			}
		}
		if(l>=k)	ans=ans+l-k+1;
	}
	cout<<ans<<endl;
	return 0;
}