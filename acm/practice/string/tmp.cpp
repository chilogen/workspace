#include <bits/stdc++.h>
using namespace std;
#define reset(a,b)	memset(a,b,sizeof(a));
#define Maxn 15000
char s[Maxn];
int sa[Maxn],t1[Maxn],t2[Maxn],cnt[Maxn],len;
void getsa(){
	int i,j,k,c,*x,*y;
	x=t1;y=t2;k='z';
	reset(cnt,0);
	for(i=0;i<len;i++){
		cnt[s[i]]++;
	}
	for(i=1;i<=m;i++)cnt[i]+=cnt[i-1];
	for(i=len-1;i>=0;i--){
		x[i]=s[i];
		cnt[s[i]]--;
		sa[cnt[s[i]]]=i;
	}
	for(j=1;j<=n;j<<=1){
		c=0;
		for(i=n-j;i<n;i++)y[c++]=i;
		for(i=0;i<n;i++){
			if(sa[i]<=j)continue;
			y[c++]=sa[i]-j;
		}
		reset(cnt,0);
		for(i=)
	}
}
int main()
{
	int i,j,k;
	scanf("%s",s);
	len=strlen(s);
	getsa();
	for(i=0;i<len;i++){
		cout<<sa[i]<<" ";
	}
	cout<<endl;
	return 0;
}