#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

LL ind[256];
LL cnt[4]={0};
vector<LL>v,v1;
string s;
map<LL,char>ma;
int main(){
	LL i,j,k;
	ind['N']=0;ind['W']=1;ind['S']=2;ind['E']=3;
	ma[0]='N';ma[1]='W';ma[2]='S';ma[3]='E';
	cin>>s;
	k=s.length();
	for(i=0;i<k;i++){
		cnt[ind[(LL)s[i]]]++;
	}
	for(i=0,j=0,k=0;i<4;i++){
		if(cnt[i]==0){
			v.push_back(i);
		}
		else v1.push_back(i);
	}
	if(v.size()==1){
		cout<<ma[v[0]]<<endl;
		return 0;
	}
	if(v.size()==2){
		i=v[0];j=v[1];
		if((i+2)%4==j){
			cout<<"X\n";
			return 0;
		}
		for(i=0;i<2;i++){
			cout<<ma[v[0]]<<ma[v[0]]<<ma[v[1]]<<ma[v[1]]<<endl;
			return 0;
		}
	}
	cout<<"X\n";
	return 0;
}