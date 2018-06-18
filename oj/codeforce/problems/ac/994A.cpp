#include <bits/stdc++.h>
using namespace std;
int a[20],n,m;
set<int>s;
int main(){
	cin>>n>>m;
	int i,j;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<m;i++){
		cin>>j;
		s.insert(j);
	}
	for(i=0;i<n;i++){
		if(s.count(a[i])!=0)cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}