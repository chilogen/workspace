#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,h,a,b,k;
LL cmp(LL x){
	if(x>b)return 1;
	if(x<a)return -1;
	return 0;
}
int main(){
	cin>>n>>h>>a>>b>>k;
	LL i,m,x1,x2,y1,y2;
	for(i=0;i<k;i++){
		m=0;
		cin>>x1>>y1>>x2>>y2;
		if(x1==x2){
			cout<<abs(y1-y2)<<endl;
			continue;
		}
		m=abs(x1-x2);
		if(cmp(y1)==-1&&cmp(y2)==-1)m+=(abs(a-y1)+abs(a-y2));
		else if(cmp(y1)==1&&cmp(y2)==1)m+=(abs(b-y1)+abs(b-y2));
		else m+=abs(y1-y2);
		cout<<m<<endl;
	}
	return 0;
}