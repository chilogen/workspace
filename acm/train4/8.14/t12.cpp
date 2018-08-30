#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
string z,x,y;
int l,r,lenz,lenx,leny;
vector<pair<int,int> >pos[2];
int fail[maxn];
void getfail(string patten){
	fail[0]=0;
	int i=0,j=1,k=patten.length();
	while(j<k){
		fail[j]=i;
		if(patten[i]==patten[j])	i++;
		else	i=0;
		j++;
	}
}
int find(string s,string patten){
	int i,j,ls=s.length(),lp=patten.length();
	for(i=0,j=0;i<ls;i++){
		while(j!=0&&patten[j]!=s[i])	j=fail[j];
		if(patten[j]==s[i])	j++;
		if(j==lp)	return i-j+1;
	}
	return -1;
}
void solve(){
	lenz=z.length();lenx=x.length();leny=y.length();
	pos[0].clear();pos[1].clear();
	int j;
	string tz=z;
	reverse(tz.begin(),tz.end());

	getfail(x);
	j=find(z,x);
	if(j==-1)return;
	pos[0].push_back(make_pair(j,j+lenx-1));
	reverse(x.begin(),x.end());
	getfail(x);
	j=find(tz,x);
	if(j!=-1)pos[0].push_back(make_pair(lenz-j-lenx,lenz-j-1));

	getfail(y);
	j=find(z,y);
	if(j==-1)return;
	pos[1].push_back(make_pair(j,j+leny-1));
	reverse(y.begin(),y.end());
	getfail(y);
	j=find(tz,y);
	if(j!=-1)pos[1].push_back(make_pair(lenz-j-leny,lenz-j-1));
}
inline bool between(int a,int s,int t){
	return (a>=s&&a<=t);
}
bool inter(pair<int,int>p1,pair<int,int>p2){
	if(between(p1.first,p2.first,p2.second))return true;
	if(between(p1.second,p2.first,p2.second))return true;
	if(between(p2.first,p1.first,p1.second))return true;
	if(between(p2.second,p1.first,p1.second))return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	int k,l,t;
	cin>>t;
	while(t--){
		cin>>z>>x>>y;
		solve();
		k=pos[0].size();l=pos[1].size();
		if(k==0||l==0){
			cout<<"NO\n";
			continue;
		}
		if((!inter(pos[0][0],pos[1][l-1]))||(!inter(pos[0][k-1],pos[1][0])))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}