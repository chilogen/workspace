#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1000000007,maxnode=2e7;
LL ch[maxnode][2]={0},val[maxnode]={0},len[maxnode]={0},sz=0,n,m,ans;
char cr[maxnode];
string str;
void insert(LL x){
	LL i,k,l=str.length();
	for(i=0,k=0;i<l;i++){
		val[k]+=x;val[k]%=mod;
		if(!ch[k][0]){
			ch[k][0]=++sz;
			len[ch[k][0]]=len[k]+1;
			k=ch[k][0];
			cr[k]=str[i];
			continue;
		}
		k=ch[k][0];
		if(cr[k]==str[i])continue;
		while(ch[k][1]&&cr[k]!=str[i])k=ch[k][1];
		if(cr[k]!=str[i]){
			ch[k][1]=++sz;
			len[ch[k][1]]=len[k];
			k=ch[k][1];
			cr[k]=str[i];
		}
	}
	val[k]+=x;val[k]%=mod;
}
void finds(LL x){
	LL i,j,k,l=str.length();
	vector<LL>v;
	for(i=0,k=0;i<l;i++){
		if(!ch[k][0])break;
		j=k;
		k=ch[k][0];
		if(cr[k]==str[i]){
			if(val[k]!=val[j])v.push_back(j);
			continue;
		}
		while(ch[k][1]&&cr[k]!=str[i])k=ch[k][1];
		if(cr[k]!=str[i]){k=j;break;}
		if(val[k]!=val[j])v.push_back(j);
	}
	ans=(val[k]*len[k]*x)%mod;
	l=val[k];
	while(!v.empty()){
		j=v[v.size()-1];v.pop_back();
		ans+=(val[j]-l)*len[j]*x;
		ans%=mod;
		l=val[j];
	}
}
int main(){
	ios::sync_with_stdio(false);
	LL i,k;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>str>>k;
		insert(k);
	}
	cin>>m;
	for(i=0;i<m;i++){

		cin>>str>>k;
		finds(k);
		cout<<ans<<endl;
	}
	return 0;
}
