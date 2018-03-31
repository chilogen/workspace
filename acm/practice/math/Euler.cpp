#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5;
LL phi[N];

//phi(j)=j*(1-1/p1)*(1-1/p2)=j*(p1-1)/p1*(p2-1)/p2;
inline void solve1(){
	LL i,j;
	memset(phi,0,sizeof(phi));
	phi[1]=1;
	for(i=2;i<N;i++){
		if(phi[i])continue;//not a prime
		for(j=i;j<N;j+=i){
			if(!phi[j])phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
	}
}
inline LL solve2(LL n){
	LL i,j=sqrt(n+0.5),ans=n;
	for(i=2;i<=j;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)	ans=ans/n*(n-1);
	return ans;
}

/*线性筛O(n)时间复杂度内筛出maxn内欧拉函数值*/
LL m[N],p[N],pt;//m[i]是i的最小素因数，p是素数，pt是素数个数
 
void solve3(){
	memset(phi,0,sizeof(phi));
    LL i,j,k;
    phi[1]=1;
    for(i=2;i<N;i++){
        if(!m[i])//i是素数
            p[pt++]=m[i]=i,phi[i]=i-1;
        for(j=0;j<pt&&(k=p[j]*i)<N;j++)
        {
            m[k]=p[j];
            if(m[i]==p[j])//为了保证以后的数不被再筛，要break
            {
                phi[k]=phi[i]*p[j];
            /*这里的phi[k]与phi[i]后面的∏(p[i]-1)/p[i]都一样（m[i]==p[j]）
            只差一个p[j]，就可以保证∏(p[i]-1)/p[i]前面也一样了*/
                break;    
            }
            else
                phi[k]=phi[i]*(p[j]-1);//积性函数性质，f(i*k)=f(i)*f(k)
        }
    }
}

int main(){
	solve1();
	LL i;
	cin>>i;
	cout<<phi[i]<<endl;
	solve3();
	cout<<phi[i]<<endl;
	cout<<solve2(4)<<endl;
	return 0;
}