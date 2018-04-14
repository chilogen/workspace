#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[3],ans=0;
int main(){
	cin>>a[0]>>a[1]>>a[2];
	while(a[0]!=a[1]||a[0]!=a[2]||a[1]!=a[2]){
		sort(a,a+3);
		if(a[2]-a[0]>=2){
			a[0]+=2;
			ans++;
		}
		else{
			a[0]+=1;
			a[1]+=1;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}