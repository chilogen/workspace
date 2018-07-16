#include <bits/stdc++.h>
using namespace std;
int cnt[30],n;
char seat[30][30];
int main(){
	int i,j,k,c,c1,c2;
	while(cin>>n){
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>seat[i][j];
				cnt[seat[i][j]-'A']++;
			}
		}
		for(c=0;c<26;c++){
			if(cnt[c]==1||cnt[c]>n)c1=c;
			if(cnt[c]==n-1&&cnt[c]!=0)c2=c;
		}
		k=0;
		for(i=0;i<n&&!k;i++){
			memset(cnt,0,sizeof(cnt));
			for(j=0;j<n&&!k;j++){
				cnt[seat[i][j]-'A']++;
			}
			if(cnt[c2]==0){
				for(j=0;j<n&&!k;j++){
					if(seat[i][j]=='A'+c1){
						for(c=0;c<n;c++){
							if(c==i)continue;
							if(seat[c][j]=='A'+c2)break;
						}
						if(c==n){
							cout<<i+1<<" "<<j+1<<" "<<char(c2+'A')<<endl;
							k=1;
						}
					}
				}
			}
		}
	}
	return 0;
}