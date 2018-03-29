#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,n,ans=0;
	char s[110];
	scanf("%d%s",&n,s+1);
	for(i=2;i<=n;i=i+2){
		for(j=1;j<=i/2;j++){
			if(s[j]!=s[i/2+j])	break;
		}
		if(j==i/2+1)	ans=i/2;
	}
	if(ans==0)cout<<n<<endl;
	else cout<<n-ans+1<<endl;
	return 0;
}