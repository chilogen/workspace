/*
26 jan 2018 week1
cdoj 1833

*trick 1:	"111" is a dicisor of 3,so "222","333"...etc can divide 3,so we can only
			calculate 3 to 999,and set other positions to the Maxinum
*trick 2:	however,like testcase 2 4 7 2,if apply trick 1 on it,will get an answer -1,
			but the right answer should be "7722".So,after trick 1 done,we should also
			calculate 999 to 9999,and set other positions to the Maxinum

*/
#include <bits/stdc++.h>
using namespace std;
int n,k,p,vis[10]={0};
bool ok(int x){
	int i=0;
	while(x){
		if(!vis[x%10])	return false;
		x=x/10;
		i++;
	}
	if(i!=p)	return false;
	return true;
}
int main()
{
	int i,j,l,ans=-1,m=-1;
	cin>>n>>k;
	p=k%3;
	for(i=0;i<n;i++){
		cin>>j;
		vis[j]=1;
		if(j>m)	m=j;
	}

	//
	if(m==0&&k==1){
		cout<<0<<endl;
		return 0;
	}
	else if(m==0&&k>1){
		cout<<-1<<endl;
		return 0;
	}
	//

	//
	if(p==0){
		for(i=0;i<k;i++)	cout<<m;
		cout<<endl;
		return 0;
	}
	//

	l=3;
	while(l<1000){
		if(ok(l))	ans=l;
		l+=3;
	}
	if(ans==-1&&p+3<=k)
	{
		p+=3;
		while(l<9999){
			if(ok(l))	ans=l;
			l+=3;
		}
	}

	if(ans==-1)	cout<<-1<<endl;
	else{
		for(i=0;i<k-p;i++)	cout<<m;
		cout<<ans<<endl;
	}
	return 0;
}