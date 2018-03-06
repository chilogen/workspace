#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,a,b,r=0,i,j,k,l;
	queue<LL>v[2];
	cin>>n>>a>>b;
	if(a>b){
		i=a;
		a=b;
		b=i;
	}
	for(i=1;i<=n;i++)v[0].push(i);
	i=1;
	while(n>1){
		j=!i;
		r++;
		while(!v[j].empty()){
			k=v[j].front();
			v[j].pop();
			l=v[j].front();
			v[j].pop();
			if(k==a&&l==b){
				if(n==2)
					cout<<"Final!"<<endl;
				else cout<<r<<endl;
				return 0;
			}
			if(k==a||k==b){
				v[i].push(k);
				continue;
			}
			if(l==a||l==b){
				v[i].push(l);
				continue;
			}
			v[i].push(k);
		}
		n>>=1;
		i=!i;
	}
	cout<<"Final!"<<endl;
	return 0;
}