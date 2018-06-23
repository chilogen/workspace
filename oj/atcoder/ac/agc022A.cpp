#include <bits/stdc++.h>
using namespace std;
int vis[26]={0},a[26];
char s[30];
int main(){
	scanf("%s",s);
	int i,j,k,l,len=strlen(s);
	for(i=0;i<len;i++){
		a[i]=s[i]-'a';
		vis[a[i]]=1;
	}
	if(len<26){
		for(i=0;i<26;i++){
			if(vis[i]==0)s[len]='a'+i;
			else continue;
			for(i=0;i<=len;i++)cout<<s[i];
			cout<<endl;
			return 0;
		}
	}
	vis[a[25]]=0;
	for(i=24;i>=0;i--){
		for(j=a[i]+1;j<26;j++){
			if(vis[j]==0){
				a[i]=j;len=i+1;
				for(k=i+1;k<len;k++){
					for(l=25;l>=0;l--){
						if(vis[l]==0){
							vis[l]=1;
							a[k]=l;
							break;
						}
					}
				}
				for(i=0;i<len;i++){
					printf("%c",a[i]+'a');
				}
				printf("\n");
				return 0;
			}
		}
		vis[a[i]]=0;
	}
	cout<<-1<<endl;
	return 0;
}