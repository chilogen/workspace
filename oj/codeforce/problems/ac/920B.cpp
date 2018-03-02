#include <bits/stdc++.h>
using namespace std;
int t,n,l[2000],r[2000],ans[2000];
int main(){
	int i,j;
	cin>>t;
	while(t--){
		queue<int>q;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>l[i]>>r[i];
			q.push(i);
		}
		j=0;
		while(!q.empty()){
			i=q.front();	q.pop();
			while(j<l[i])j++;
			if(j>r[i])	ans[i]=0;
			else ans[i]=j++;
		}
		for(i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}