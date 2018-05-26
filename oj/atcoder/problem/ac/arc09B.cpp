#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200000],n,p=0,ans=0,l=0;
queue<int>q;
bool check(LL x){
	if((a[x]^p)==a[x]+p){
		q.push(x);
		p=a[x]+p;
		return true;
	}
	return false;
}
inline void popfront(){
	p-=a[q.front()];
	q.pop();
}
int main(){
	LL i;
	bool k;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	for(i=0;i<n;i++){
		k=check(i);
		while(!k){popfront();k=check(i);}
		if(k)ans+=(q.size()-1);
	}
	cout<<ans+n<<endl;
	return 0;
}