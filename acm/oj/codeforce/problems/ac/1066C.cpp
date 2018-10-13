#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct query{
	char cmd;
	LL id,ans;
}q[200010];
LL pos[200010];
int main(){
	deque<LL>dq;
	LL Q,i,j,l,r;
	cin>>Q;
	for(i=0;i<Q;i++){
		cin>>q[i].cmd>>q[i].id;
		if(q[i].cmd=='L')dq.push_front(q[i].id);
		if(q[i].cmd=='R')dq.push_back(q[i].id);
	}
	l=r=0;
	while(!dq.empty()){
		j=dq.front();
		dq.pop_front();
		pos[j]=r;
		r++;
	}
	for(i=Q-1;i>=0;i--){
		if(q[i].cmd=='L')l++;
		if(q[i].cmd=='R')r--;
		if(q[i].cmd=='?')q[i].ans=min(pos[q[i].id]-l,r-pos[q[i].id]-1);
	}
	for(i=0;i<Q;i++)if(q[i].cmd=='?')cout<<q[i].ans<<endl;
	return 0;
}