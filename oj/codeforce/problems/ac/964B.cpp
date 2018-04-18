#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,t,ans1=0,ans2=0,cnt=0,k[1010];
int main(){
	int i;
	cin>>n>>a>>b>>c>>t;
	for(i=0;i<n;i++){
		cin>>k[i];
		if(k[i]<=t){
			ans1+=((t-k[i])*(c-b)+a);
			ans2+=a;
		}
	}
	cout<<max(ans2,ans1)<<endl;
	return 0;
}