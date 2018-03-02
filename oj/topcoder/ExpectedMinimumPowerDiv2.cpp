#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class ExpectedMinimumPowerDiv2{
private:
	LL c[51][51],p[51];
	double a,b;
public:
	ExpectedMinimumPowerDiv2(){
		a=b=0;
		LL i,j,two=2;
		c[0][0]=1;p[0]=1;
		for(i=1;i<=50;i++){
			p[i]=two<<(i-1);
			c[i][0]=c[i][i]=1;
			for(j=1;j<i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
		}
	}
	double findExp(int n, int x){
		LL i,j,k;
		double q,e;
		for(i=1;i<=n;i++){
			if(n-i<x-1)break;
			a+=p[i]*c[n-i][x-1];
			b+=c[n-i][x-1];
		}
		return a/b;
	}
}tc;
int main(){
	int x,n;
	cin>>n>>x;
	cout<<tc.findExp(n,x)<<endl;
	return 0;
}