#include <bits/stdc++.h>
using namespace std;
int sume[300010]={0},sumw[300010]={0};
int n;
int main(){
	string s;
	cin>>n>>s;
	int i,k=s.length(),ans=3000010;
	for(i=0;i<k;i++){
		sumw[i+1]=sumw[i];
		sume[i+1]=sume[i];
		if(s[i]=='W')sumw[i+1]++;
		else sume[i+1]++;
	}
	for(i=1;i<=k;i++){
		ans=min(ans,sumw[i-1]+sume[k]-sume[i]);
	}
	cout<<ans<<endl;
	return 0;
}