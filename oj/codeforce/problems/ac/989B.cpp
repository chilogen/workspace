#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string str;
void fill(){
	LL i,j=str.length();
	for(i=0;i<j;i++)if(str[i]=='.')str[i]='0';
}
int main(){
	LL n,p,i,j,nex[2010];
	cin>>n>>p>>str;
	memset(nex,-1,sizeof(nex));
	for(i=0,j=p;j<n;i++,j++)nex[i]=j;
	for(i=0,j=0;nex[i]!=-1&&!j;i++){
		if(str[i]=='.'){
			if(str[nex[i]]=='.'){
				str[i]='0';
				str[nex[i]]='1';
				fill();
				j=1;
				continue;
			}
			if(str[nex[i]]=='0')str[i]='1';
			else str[i]='0';
			fill();
			j=1;
			continue;
		}
		else if(str[i]=='0'){
			if(str[nex[i]]==str[i])continue;
			if(str[nex[i]]!='1')str[nex[i]]='1';
			fill();
			j=1;
			continue;
		}
		else if(str[i]=='1'){
			if(str[nex[i]]==str[i])continue;
			if(str[nex[i]]!='0')str[nex[i]]='0';
			fill();
			j=1;
			continue;
		}
	}
	if(j)cout<<str<<endl;
	else cout<<"No\n";
	return 0;
}