#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL cnt[2]={0},a[3];
int main(){
	LL i;
	for(i=0;i<3;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(cnt[0]==1){
		for(i=0;i<3;i++)
			if(a[i]==0)
				cout<<(char)('A'+i);
		return 0;
	}
	if(cnt[1]==1){
		for(i=0;i<3;i++)
			if(a[i]==1)
				cout<<(char)('A'+i);
		return 0;
	}
	cout<<"*";
	return 0;
}