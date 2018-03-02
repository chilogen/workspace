#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct cir{
	LL a[1000010];
	LL size;
	void set(LL x){
		size=x;
	}
	LL get(LL x){
		return a[(x+1)%size];
	}
	void arrange(LL x){
		LL i;
		for(i=0;i<size;i++){
			a[i]=x++;
		}
	}
}c;
LL p[1000010];
int main(){
	LL n,a,b,sa,sb,i,j,k;
	cin>>n>>a>>b;
	if(a>b){
		a^=b;
		b^=a;
		a^=b;
	}
	sa=n/a;
	while(sa>=0&&(n-sa*a)%b!=0)sa--;
	if(sa==-1){
		cout<<-1<<endl;
		return 0;
	}
	sb=(n-sa*a)/b;
	c.set(a);
	for(i=0,j=1;i<sa;i++,j+=a){
		c.arrange(j);
		for(k=0;k<a;k++){
			p[j+k]=c.get(k);
		}
	}
	c.set(b);
	for(i=0;i<sb;i++,j+=b){
		c.arrange(j);
		for(k=0;k<b;k++){
			p[j+k]=c.get(k);
		}
	}
	for(i=1;i<=n;i++)cout<<p[i]<<" ";
	cout<<endl;
	return 0;
}