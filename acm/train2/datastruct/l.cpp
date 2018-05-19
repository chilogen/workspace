#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e5+10;
LL fat[maxn],color[maxn];
set<LL>s[maxn];
LL n,m;
LL getfat(LL x){
	if(x==fat[x])return x;
	else return fat[x]=getfat(fat[x]);
}
int main(){
	LL x,y,c,i,j,k;
	char a;
	for(i=0;i<maxn;i++)fat[i]=color[i]=i;
	cin>>n>>m;
	while(m--){
		a=getchar();
		while(a!='A'&&a!='Q')a=getchar();
		scanf("%lld%lld",&x,&y);
		j=getfat(x);
		k=getfat(y);
		switch(a){
			case 'A':{
				scanf("%lld",&c);
				if(c==1){
					fat[k]=j;
					color[k]=color[j];
					set<LL>::iterator p=s[k].begin();
					while(p!=s[k].end()){
						s[j].insert(*p);
						p++;
					}
				}
				else{
					s[j].insert(k);
					s[k].insert(j);
				}
				break;
			}
			case 'Q':{
				if(j==k)cout<<"1\n";
				else{
					if(s[j].count(k)!=0||s[k].count(j)!=0)cout<<"2\n";
					else cout<<"3\n";
				}
				break;
			}
		}
	}
	return 0;
}