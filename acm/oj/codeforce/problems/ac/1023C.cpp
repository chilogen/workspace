#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
LL vis[200010]={0};
stack<LL>sta;
string s,ans;
string lef="(",rig=")";
int main(){
	cin>>n>>k>>s;
	LL i,len=s.length();
	ans="";
	for(i=0;i<len&&k>0;i++){
		if(s[i]=='(')sta.push(i);
		else{
			vis[sta.top()]=1;
			vis[i]=1;
			k-=2;
			sta.pop();
		}
	}
	for(i=0;i<len;i++)if(vis[i])cout<<s[i];
	cout<<endl;
	return 0;
}