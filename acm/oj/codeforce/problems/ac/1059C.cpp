#include <bits/stdc++.h>
using namespace std;
int n;
queue<int>q[2],*p1=&q[0],*p2=&q[1];
vector<int>ans;
int main(){
	int i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++)q[0].push(i);
	for(i=0,j=2;i<n;i++,j*=2){
		if(p1->size()==3){
			ans.push_back(j/2);
			ans.push_back(j/2);
			ans.push_back(3*j/2);
			break;
		}
		while(!p1->empty()){
			l=p1->front();p1->pop();
			k=l*j/2;
			if(k%j==0)p2->push(l/2);
			else ans.push_back(j/2);
		}
		swap(p1,p2);
	}
	for(i=0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}