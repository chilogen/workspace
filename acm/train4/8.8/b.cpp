#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+10;
const LL mod=1e9+7;
int cnt[maxn][26];
vector<string>v;
int res[26],vis[26];
struct node{
	LL c;
	LL count;
};
struct cmp{
	bool operator()(node a,node b){return a.count<b.count;}
};
LL tonum(LL x){
	LL i,a=0,l=v[x].length();
	for(i=l-1;i>=0;i--){
		a*=26;
		a+=res[v[x][i]-'a'];
		a%=mod;
	}
	return a;
}
map<LL,LL>ma;
void solve(LL x){
	LL i,j;
	res[x]=1;
	for(i=1;i<26;i++){
		j=ma[i];
		if(!vis[j]){res[j]=0;return;}
		else res[j]=i+1;
	}
}
int main(){
	LL n,i,j,k,ml,ans,Kase=1;
	string s;
	while(cin>>n){
		v.clear();
		ma.clear();
		ml=ans=0;
		memset(res,-1,sizeof(res));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++){
			cin>>s;
			vis[s[0]-'a']=1;
			reverse(s.begin(),s.end());
			v.push_back(s);
			k=s.length();ml=max(ml,k);
			for(j=0;j<k;j++)
				cnt[j][s[j]-'a']++;
		}
		for(i=0;i<ml;i++){
			for(j=0;j<26;j++){
				k=cnt[i][j]/26;
				cnt[i][j]-=(k*26);
				cnt[i+1][j]+=k;
				if(k>=1)ml++;
			}
		}
		for(ml=25;i>=0&&ml>=0;i--){
			priority_queue<node,vector<node>,cmp>q;
			for(j=0;j<26;j++)if(cnt[i][j]!=0)q.push((node){j,cnt[i][j]});
			while(!q.empty()){
				node tn=q.top();q.pop();
				if(res[tn.c]!=-1)continue;
				res[tn.c]=ml;
				ma[ml]=tn.c;
				ml--;
			}
		}
		for(i=0;i<26;i++){
			if(res[i]!=0)continue;
			solve(i);
			break;
		}
		for(i=0;i<n;i++){
			j=tonum(i);
			ans+=j;
			ans%=mod;
		}
		cout<<"Case #"<<Kase++<<": "<<ans<<endl;
		//for(i=0;i<26;i++)cout<<(char)('a'+i)<<" : "<<res[i]<<endl;
	}
	return 0;
}