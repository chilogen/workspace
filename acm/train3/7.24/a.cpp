#include <iostream>
using namespace std;
typedef long long LL;
int x[]={1,0,1,-1},y[]={0,1,1,-1};
int s[2]={0};
int t,n;
int main(){
	int i,j;
	cin>>t;
	while(t--){
		s[0]=s[1]=0;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>j;
			j--;
			s[0]+=x[j];
			s[1]+=y[j];
		}
		if(s[0]>s[1]){
			cout<<"Kobayashi\n";
		}
		else if(s[0]<s[1]){
			cout<<"Tohru\n";
		}
		else cout<<"Draw\n";
	}
	return 0;
}