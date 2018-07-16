#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
vector<LL>v[5];
LL a[5];
int main(){
	LL i,j,k;
	for(i=0;i<4;i++)cin>>a[i];
	a[4]=a[0]+a[1]+a[2]+a[3];
	for(i=0;i<5;i++){
		v[i].push_back(1);
		for(j=2;j<=a[i];j++   )v[i].push_back(j);
	}
	for(i=0;i<4;i++){
		vector<LL>::iterator p1=v[i].begin(),p2;
		while(p1!=v[i].end()){
			p2=v[4].begin();
			while(*p1!=1){
				j=__gcd(*p1,*p2);
				(*p1)=(*p1)/j;
				(*p2)=(*p2)/j;
				p2++;
			}
			p1++;
		}
	}
	for(i=0,j=v[4].size(),k=1;i<j;i++){
		k*=v[4][i];
		k%=mod;
	}
	cout<<k<<endl;
	return 0;
}