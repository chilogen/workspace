#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int solve[maxn]={0},penalty[maxn]={0},vis[maxn]={0},n,m;
queue<int>q;
bool higher(int x){
	if(solve[x]==solve[1])return penalty[x]<penalty[1];
	return solve[x]>solve[1];
}
int main(){
	int i,k,l,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		solve[a]++;
		penalty[a]+=b;
		if(a==1){
			k=q.size();
			while(k--){
				l=q.front();q.pop();
				if(!higher(l))vis[l]=0;
				else q.push(l);
			}
		}
		else if(!vis[a]){
			if(higher(a)){
				vis[a]=1;
				q.push(a);
			}
		}
		cout<<q.size()+1<<endl;
	}
	return 0;
}