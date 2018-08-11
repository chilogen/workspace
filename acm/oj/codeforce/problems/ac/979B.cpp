#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,cnt[3],tcount[100];
int main(){
	LL i,j,len;
	string s[3];
	cin>>n;
	for(i=0;i<3;i++){
		cin>>s[i];
		memset(tcount,0,sizeof(tcount));
		for(j=0;j<(LL)s[i].length();j++)tcount[s[i][j]-'A']++;
		cnt[i]=0;
		for(j=0;j<100;j++)cnt[i]=max(tcount[j],cnt[i]);
		cnt[i]=s[i].length()-cnt[i];
	}
	string name[3];
	name[0]="Kuro";name[1]="Shiro";name[2]="Katie";
	for(i=0;i<3;i++){
		if(n==1&&cnt[i]==0){
			cnt[i]=1;
			continue;
		}
		if(n<=cnt[i])cnt[i]-=n;
		else cnt[i]=0;
	}
	len=min(cnt[0],min(cnt[1],cnt[2]));
	for(i=0,j=0;i<3;i++)if(cnt[i]==len)j++;
	if(j>=2){cout<<"Draw\n";return 0;}
	for(i=0;i<3;i++)if(cnt[i]==len){cout<<name[i]<<endl;break;}
	return 0;
}