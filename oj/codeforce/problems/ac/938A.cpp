#include <bits/stdc++.h>
using namespace std;
int n;
char c[1000];
int show[1000]={0};
int main(){
	int i,j,k;
	cin>>n;
	c[0]='1';
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n;i++){
		if((c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'||c[i]=='y')&& \
		  (c[i-1]=='a'||c[i-1]=='e'||c[i-1]=='i'||c[i-1]=='o'||c[i-1]=='u'||c[i-1]=='y'))
			show[i]=1;
	}
	for(i=1;i<=n;i++){
		if(!show[i])cout<<c[i];
	}
	cout<<endl;
	return 0;
}