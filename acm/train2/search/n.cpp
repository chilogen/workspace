#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=1000;
vector<LL>v[2];
LL a,b,c,d,ans=0;
bool cmp(LL x,LL y){return x>y;}
int main(){
	LL x1,x2,x3,x4;
	ios::sync_with_stdio(false);
	cin>>a>>b>>c>>d;
	for(x1=1;x1<=maxn;x1++)for(x2=1;x2<=maxn;x2++)v[0].push_back(x1*x1*a+x2*x2*b);
	for(x3=1;x3<=maxn;x3++)for(x4=1;x4<=maxn;x4++)v[1].push_back(x3*x3*c+x4*x4*d);
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end(),cmp);
	x1=x2=0;a=v[0].size();b=v[1].size();
	while(x1<a&&x2<b){
		x3=v[0][x1]+v[1][x2];
		if(x3==0){
			c=x1+1;
			while(c<a){
				if(v[0][c]!=v[0][x1])break;
				c++;
			}
			d=x2+1;
			while(d<b){
				if(v[1][d]!=v[1][x2])break;
				d++;
			}
			ans+=(16*(c-x1)*(d-x2));
			x1=c;	x2=d;
		}
		else if(x3>0)x2++;
		else x1++;
	}
	cout<<ans<<endl;
	return 0;
}