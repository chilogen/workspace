#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=2e5+10;
LL n,m,a[maxn],b[maxn],w[maxn],s[maxn],fat[2010];
set<LL>v[2010];
bool cmp(LL a,LL b){return w[a]<w[b];}
LL getfat(LL x){
	if(x==fat[x])return x;
	return fat[x]=getfat(fat[x]);
}
int main(){
	LL i,j,k;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a[i]>>b[i]>>w[i];
		s[i]=i;
	}
	for(i=0;i<2010;i++)fat[i]=i;
	sort(s,s+m,cmp);
	for(i=0;i<m;i++){
		j=getfat(a[s[i]]);k=getfat(b[s[i]]);
		if(j==k&&(v[a[s[i]]].count(w[s[i]])!=0||v[b[s[i]]].count(w[s[i]])!=0)){
			cout<<"zin\n";
			return 0;
		}
		if(j!=k){
			fat[j]=k;
			v[a[s[i]]].insert(w[s[i]]);
			v[b[s[i]]].insert(w[s[i]]);
		}
	}
	cout<<"ogisosetsuna\n";
	return 0;
}

/*
4 4
1 2 1
1 3 1
2 3 5
2 4 5
before sixth

4 5
1 2 1
1 3 1
2 3 5
2 4 5
3 4 5
seventh
*/