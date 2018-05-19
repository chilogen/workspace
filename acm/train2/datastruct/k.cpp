//same 0
//diff 1

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
LL fat[maxn],relation[maxn];
LL n,m,x,y,v;
char c;
LL getfat(LL x,LL &r){
	int i;
	r^=relation[x];
	if(x==fat[x])return x;
	i=getfat(fat[x],r);
	relation[x]^=relation[fat[x]];
	return fat[x]=i;
}
int main(){
	LL i,j,k,r1,r2;
	for(i=0;i<maxn;i++){
		fat[i]=i;
		relation[i]=0;
	}
	cin>>n>>m;
	while(m--){
		cin>>c>>x>>y;
		switch(c){
			case 'A':{
				cin>>v;
				r1=r2=0;
				j=getfat(x,r1);
				k=getfat(y,r2);
				relation[k]^=relation[j];
				fat[k]=j;
				v--;
				relation[k]=relation[k]^v^r1^r2;
				break;
			}
			case 'Q':{
				r1=r2=0;
				j=getfat(x,r1);
				k=getfat(y,r2);
				if(j!=k){
					cout<<3<<endl;
					break;
				}
				j=r1^r2;
				cout<<j+1<<endl;
				break;
			}
		}
	}
	return 0;
}