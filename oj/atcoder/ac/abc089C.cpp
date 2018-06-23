#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL num[5]={0},n,ans=0;
int main(){
	LL i,j,k;
	cin>>n;
	char s[50];
	while(n--){
		scanf("%s",s);
		if(s[0]=='M')num[0]++;
		if(s[0]=='A')num[1]++;
		if(s[0]=='R')num[2]++;
		if(s[0]=='C')num[3]++;
		if(s[0]=='H')num[4]++;
	}
	n=0;
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			for(k=j+1;k<5;k++){
				ans+=(num[i]*num[j]*num[k]);
				n++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}