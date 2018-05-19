#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1e6+10;
LL fat[maxn],relation[maxn];
LL getfat(LL x)
{
	LL i;
	if(x==fat[x]) return x;
	else
	{
		i=getfat(fat[x]);
		relation[x]=(relation[x]+relation[fat[x]])%3;
		return fat[x]=i;
	}
}
LL n,m,c,x,y;
int main()
{
	LL i,j,k;
	for(i=1;i<=maxn;i++)
	{
		fat[i]=i;
		relation[i]=0;
	}
	cin>>n>>m;
	i=-1;
	while(m--)
	{
		i++;i%=3;
		cin>>c>>x>>y;
		if(c==2&&x==y){
			cout<<i+1<<endl;
			return 0;
		}
		else{
			j=getfat(x);k=getfat(y);
			if(j==k&&(relation[x]-relation[y]+3)%3!=c-1){
				cout<<i+1<<endl;
				return 0;
			}
			fat[j]=k;
			relation[j]=(-relation[x]+c-1+relation[y]+3)%3;
		}
	}
	cout<<-1<<endl;
	return 0;
}