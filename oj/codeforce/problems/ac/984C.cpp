#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)  
{  
    LL t;  
    while(b)  
    {  
        t = a;  
        a = b;  
        b = t%b;  
    }  
    return a;  
}
int main(){
	LL n,p,q,b,GCD;
	cin>>n;
	while(n--){
		scanf("%lld%lld%lld",&p,&q,&b);
		if(q==1||p==0){
			cout<<"Finite\n";
			continue;
		}
		GCD=gcd(p,q);
		q=q/GCD;
		while(1){
			GCD=gcd(q,b);
			if(GCD==1&&q!=1){cout<<"Infinite\n";break;}
			if(GCD==1&&q==1){cout<<"Finite\n";break;}
			while(q%GCD==0)q=q/GCD;
		}
	}
	return 0;
}