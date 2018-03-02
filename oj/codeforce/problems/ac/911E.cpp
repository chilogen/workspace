#include <bits/stdc++.h>
using namespace std;
stack<int>s;
int n,k,now=1,vis[200010]={0},ans[200010];
int main(){
	int i,j;
	cin>>n>>k;
	for(i=0;i<k;i++){
		cin>>ans[i];
		s.push(ans[i]);
		vis[ans[i]]=1;
		while(!s.empty()&&s.top()==now){
			s.pop();
			now++;
		}
	}
	while(!s.empty()){
		i=s.top()-1;
		if(s.top()==now){
			s.pop();
			now++;
		}
		else if(!vis[i]){
			ans[k++]=i;
			s.push(i);
			vis[i]=1;
		}
		else if(vis[i]||now==n+1){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(i=n;i>=1;i--){
		if(!vis[i])	ans[k++]=i;
	}
	for(i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}