#include <bits/stdc++.h>
using namespace std;
struct SparseTable{
//array indentity from 0 to size-1
	int **ST;
	int num,slog;
	SparseTable(){ST=NULL;}
	SparseTable(int size){init(size);}
	void init(int size){
		int i;
		num=size;

		//2^x<=size<2^(x+1)
		slog=floor(log(size)/log(2));

		
		ST=new int*[size];
		for(i=0;i<size;i++)ST[i]=new int[slog];
	}
	void solve(int *v){
		int i,j;
		for(i=0;i<num;i++)ST[i][0]=v[i];

		for(i=1;i<=slog;i++){
			for(j=0;j<num;j++){
				if(j+(1ll<<(i-1))>=num)break;
				ST[j][i]=cmp(ST[j][i-1],ST[j+(1ll<<(i-1))][i-1]);
			}
		}
	}
	int cmp(int x,int y){return min(x,y);}
	int RMQ(int s,int t){
		int qlog=floor(log(t-s+1)/log(2));
		return cmp(ST[s][qlog],ST[t+1-(1ll<<qlog)][qlog]);
	}
}ss;
int main(){
	int n,a[10000],i,j,k;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	ss.init(n);
	ss.solve(a);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k;
		j--;k--;
		cout<<ss.RMQ(j,k)<<endl;
	}
	return 0;
}