#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5;

struct trie{
	trie * ch[26];
	int ind;
}root;

string dic[maxn];
int dpnex[maxn],dpcnt[maxn];

void insert(int *cnt,int id){
	int i;
	trie* nx=&root;
	for(i=0;i<26;i++){
		if(nx->ch[cnt[i]]==NULL)nx->ch[cnt[i]]=new trie();
		nx=nx->ch[cnt[i]];
	}
	nx->ind=id;
}

int query(int *cnt){
	trie *nx=&root;
	int i;
	for(i=0;i<26;i++){
		if(nx->ch[cnt[i]]==NULL)return -1;
		nx=nx->ch[cnt[i]];
	}
	return nx->ind;
}

bool cmp(string a,string b){return a.length()<b.length();}

void calcnt(int *x,string &ts){
	memset(x,0,sizeof(int)*26);
	int i,l=ts.length();
	for(i=0;i<l;i++)x[ts[i]-'a']++;
}

void readic(){
	int i,j,k,n;
	int cnt[26];
	memset(dpnex,-1,sizeof(dpnex));
	cin>>n;
	for(i=1;i<=n;i++)cin>>dic[i];
	sort(dic+1,dic+n+1,cmp);
	for(i=1;i<=n;i++){
		dpcnt[i]=0;
		calcnt(cnt,dic[i]);
		insert(cnt,i);
	}
	for(i=1;i<=n;i++){
		calcnt(cnt,dic[i]);
		for(j=0;j<26;j++){
			cnt[j]++;
			k=query(cnt);
			if(k!=-1&&dpcnt[k]<dpcnt[i]+1){
				dpcnt[k]=dpcnt[i]+1;
				dpnex[k]=i;
			}
			cnt[j]--;
		}
	}
}

vector<string>q;

void solve(){
	int i,j,n;
	int cnt[26];
	string ts;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ts;
		q.push_back(ts);
	}
	readic();
	n=q.size();
	for(i=0;i<n;i++){
		calcnt(cnt,q[i]);
		j=query(cnt);
		cout<<q[i];
		if(j==-1){
			cout<<endl;
			continue;
		}
		while(dpnex[j]!=-1){
			j=dpnex[j];
			cout<<" -> "<<dic[j];
		}
		cout<<" -> .\n";
	}
}

int main(){
	solve();
	return 0;
}