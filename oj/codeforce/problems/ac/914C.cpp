#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL M=1e9+7;
LL c[1010][1010]={0};
vector<LL>v;
void calc(LL x){
	int i,j,k,l;
	for(i=0;i<=1000;i++){
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
		}
	}
	for(i=2;i<=1000;i++){
		j=x;	k=0;	l=i;
		while(j--){
			while(l){
				if(l&1)	k++;
				l=l>>1;
			}
			l=k;
			if(k==1)	break;
			else k=0;
		}
		if(j==0)	v.push_back(i);
	}
}
LL k,ans=0;
int main(){
	string s;
	cin>>s>>k;
	if(k==0){
		cout<<1<<endl;
		return 0;
	}
	if(k==1){
		cout<<s.length()-1<<endl;
		return 0;
	}
	calc(k-1);
	int i,j,l=0,n;
	for(i=0;i<s.length();i++){
		n=s.length()-i-1;
		if(s[i]=='1'){
			for(j=0;j<v.size();j++){
				if(v[j]-l<0)	continue;
				if(n>=v[j]-l)	ans=(ans+c[n][v[j]-l])%M;
				else break;
			}
			l++;
		}
	}
	for(i=0;i<v.size()&&k!=1;i++){
		if(v[i]==l){
			ans++;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}