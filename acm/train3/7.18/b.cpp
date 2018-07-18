#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
LL a[100],n,b[100],ans=1;
void check(LL x,LL y){
	string s1,s2;
	s1=s2="";
	LL i,k;
	while(x){
		if(x&1)s1+='1';
		else s1+='0';
		x>>=1;
	}
	while(y){
		if(y&1)s2+='1';
		else s2+='0';
		y>>=1;
	}
	k=max(s1.length(),s2.length());
	while((int)s1.length()<k)s1+='0';
	while((int)s2.length()<k)s2+='0';
	for(i=k-1;i>=0;i--){
		if(s1[i]=='1'&&s2[i]=='1')continue;
		if(s1[i]=='1'&&s2[i]=='0'){
			if(b[i]==-1||b[i]==1)b[i]=1;
			//else b[i]=2;
			return;
		}
		if(s1[i]=='0'&&s2[i]=='1'){
			if(b[i]==-1||b[i]=='0')b[i]=0;
			//else b[i]=2;
			return;
		}
		if(s1[i]=='0'&&s2[i]=='0')continue;
	}
}
int main(){
	LL i;
	cin>>n;
	memset(b,-1,sizeof(b));
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n-1;i++)check(a[i],a[i+1]);
	for(i=0;i<60;i++){
		if(b[i]==-1)ans<<=1;
		if(b[i]==2){
			ans=0;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}