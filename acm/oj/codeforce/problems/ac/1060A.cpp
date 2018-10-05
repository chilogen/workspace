#include <bits/stdc++.h>
using namespace std;
int cnt[2],n,ans;
string s;
int main(){
	int i,j,k;
	cin>>n>>s;
	for(i=0;i<n;i++){
		if(s[i]=='8')cnt[1]++;
		else cnt[0]++;
	}
	j=0;
	while(cnt[1]!=0){
		cnt[1]--;
		k=0;
		k+=min(cnt[0],10);
		cnt[0]-=k;
		if(k!=10){
			j=10-k;
			j=min(cnt[1],j);
			cnt[1]-=j;
			k+=j;
		}
		if(k!=10)break;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}