#include <bits/stdc++.h>
using namespace std;
char s[100010];
int len;
int a[100010],b[100010];
int main(){
	int i,j,k,f=1;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)a[i]=s[i]-'0';
	
	for(i=j=k=0;i<len;i++){
		if(a[i]==1){
			k++;
			continue;
		}
		b[j++]=a[i];
	}
	b[j]=-1;
	for(i=j=0;i<len;i++,j++){
		if(b[j]==-1)break;
		if(b[i]==2&&f){
			f=0;
			while(k--){
				a[i++]=1;
			}
		}
		a[i]=b[j];
	}
	while(k>0){
		a[i++]=1;
		k--;
	}
	for(i=0;i<len;i++)cout<<a[i];
	return 0;
}