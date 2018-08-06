#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
LL pos[110]={0},p=0;
string input;
LL tonum(){
	LL i,j,k=0;
	if(input[0]=='-'){j=-1;i=1;}
	else{j=1;i=0;}
	for(;i<(LL)input.length();i++){
		k*=10;
		k+=(input[i]-'0');
	}
	return k*j;
}
void process(){
	LL i,j,m;
	if(input[0]=='u'){
		cin>>j;
		p-=j;
	}
	else{
		m=tonum();
		j=(pos[p]+m)%n;
		if(j<0){
			i=(-j)%n;
			j=n-i;
		}
		pos[++p]=j;
	}
}
int main(){
	ios::sync_with_stdio(false);
	LL i;
	cin>>n>>k;
	for(i=0;i<k;i++){
		cin>>input;
		process();
	}
	cout<<pos[p]<<endl;
	return 0;
}