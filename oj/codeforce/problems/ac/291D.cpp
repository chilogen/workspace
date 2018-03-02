#include <bits/stdc++.h>
using namespace std;
int n,k,a[21][10010];
int main(){
	int i,j,l,m;
	cin>>n>>k;
	for(i=0,l=1;i<k;i++){
		for(j=0;j<n;j++){
			m=n-j-1;
			if(m<=l)	cout<<n<<" ";
			else if(m>2*l)	cout<<n-l<<" ";
			else cout<<n-m+l<<" ";
		}
		cout<<endl;
		l*=2;
	}
	return 0;
}