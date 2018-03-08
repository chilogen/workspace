#include <bits/stdc++.h>
using namespace std;
#define Max 150000
#define reset(a,b)	memset(a,b,sizeof(a))
int sa[Max],t1[Max],t2[Max],cnt[Max];
char ch[Max];
void getsa(int m){
	int *x=t1,*y=t2,len=strlen(ch),i,j,k,p;
	reset(cnt,0);
	reset(sa,0);
	for(i=0;i<len;i++)cnt[x[i]=ch[i]]++;
	for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
	for(i=0;i<len;i++)sa[--cnt[x[i]]]=i;
	for(k=1;k<=len;k<<=1){
		p=0;
		for(i=len-k;i<len;i++)y[p++]=i;
		for(i=0;i<len;i++)	if(sa[i]>=k)
			y[p++]=sa[i]-k;
		reset(cnt,0);
		for(i=0;i<len;i++)cnt[x[y[i]]]++;
		for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
		for(i=len-1;i>=0;i--){
			sa[--cnt[x[y[i]]]]=y[i];
		}
		swap(x,y);
		p = 1;  x[sa[0]] = 0;
        for (i = 1; i < len; i++){
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        }
        if (p >= len) break;
        m = p;
	}
}
int main(){
	int i,j;
	scanf("%s",ch);
	getsa('z');
	for(i=0;i<strlen(ch);i++)	cout<<sa[i]<<" ";
	cout<<endl;
	return 0;
}