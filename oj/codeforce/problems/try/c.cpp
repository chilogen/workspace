#include <bits/stdc++.h>
using namespace std;
double k,d,t,ti,nd,nk,ad=0,ak=0,ans=0,left,Max=1e8;
int main(){
	LL i=0,j;
	cin>>k>>d>>t;
	if(k%d!=0)ad=1;
	if(d%k!=0)ak=1;
	if(d<k)i=1;
	ti=min(k,d);
	if(ti>=t){
		cout<<t<<endl;
		return 0;
	}
	left=t-ti;ans=ti;nd=d;nk=k;
	while(t1<Max&&left>0){
		if(i){
			j=(nd/k)+ak;
			nk=j*k;
			if(nk>t){
				ans+=(t-nk)
			}
		}
		else{

		}
	}
}