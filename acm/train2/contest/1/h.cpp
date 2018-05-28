#include <bits/stdc++.h>
using namespace std;
int cnt[5][5],n,seq[600][2],sum,Case,p;
bool check1(){
	int i,j;
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			if(i==j&&cnt[i][j]!=sum/8)return false;
			if(i!=j&&cnt[i][j]!=sum/24)return false;
		}
	}
	return true;
}
bool check2(){
	int i;
	for(i=0;i<p-2;i++){
		if(seq[i][1]==seq[i+1][1]&&seq[i+1][1]==seq[i+2][1])return false;
		if(seq[i][0]==seq[i+1][0]&&seq[i+1][0]==seq[i+2][0])return false;
	}
	return true;
}
int main(){
	int k,x,y;
	cin>>n;
	for(Case=1;Case<=n;Case++){
		cout<<"Case #"<<Case<<": ";
		memset(cnt,0,sizeof(cnt));
		sum=p=0;
		cin>>k;
		while(k!=0){
			x=k%10;y=k/10;
			seq[p][0]=x;seq[p][1]=y;
			p++;
			cnt[x][y]++;
			sum++;
			cin>>k;
		}
		if(!check1()||!check2())cout<<"Not Stroop\n";
		else cout<<"Stroop\n";
	}
	return 0;
}