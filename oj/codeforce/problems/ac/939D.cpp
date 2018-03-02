#include<bits/stdc++.h>
using namespace std;
int n,fat[30];
char s[2][100010];
char ans[100010][2];
int getfat(int x){
	if(x==fat[x])	return x;
	return fat[x]=getfat(fat[x]);
}
int main(){
	int c1,c2;
	int i,j,k,t=-1,a,b;
	cin>>n;
	for(i=0;i<2;i++){
		for(j=0;j<n;j++){
			cin>>s[i][j];
		}
	}
	for(i=0;i<26;i++)fat[i]=i;
	for(i=0;i<n;i++){
		c1=s[0][i]-'a';
		c2=s[1][i]-'a';
		if(c1!=c2){
			j=getfat(c1);
			k=getfat(c2);
			if(j!=k){
				t++;
				ans[t][0]=s[0][i];
				ans[t][1]=s[1][i];
				if(j==c1){
					fat[j]=k;
				}
				else fat[k]=j;
			}
		}
	}
	cout<<t+1<<endl;
	for(i=0;i<=t;i++){
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	}
	return 0;
}