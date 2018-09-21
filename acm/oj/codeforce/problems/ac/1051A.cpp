#include <bits/stdc++.h>
using namespace std;
int t;
string s;
inline char change(int type){
	if(type==0)return 'A';
	if(type==1)return 'a';
	return '2';
}
inline int caltype(char x){
	if(x>='A'&&x<='Z')return 0;
	if(x>='a'&&x<='z')return 1;
	return 2;
}
vector<int>pos[3];

void solve(){
	int i,j,k,l=s.length();
	for(i=0;i<3;i++)pos[i].clear();
	for(i=0;i<l;i++){
		if(s[i]>='A'&&s[i]<='Z')pos[0].push_back(i);
		if(s[i]>='a'&&s[i]<='z')pos[1].push_back(i);
		if(s[i]>='0'&&s[i]<='9')pos[2].push_back(i);
	}
	for(i=0,k=0;i<3;i++)if(pos[i].size()==0)k++;
	if(k==0)return;
	if(k==1){
		for(j=0;j<3;j++)if(pos[j].size()==0)break;
		for(i=0;i<3;i++){
			if(pos[i].size()<2)continue;
			s[pos[i][0]]=change(j);
			return;
		}
		return;
	}
	if(k==2){
		for(j=0;j<3;j++)if(pos[j].size()!=0)break;
		for(i=0,k=0;i<3;i++){
			if(i==j)continue;
			s[k++]=change(i);
		}
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>s;
		solve();
		cout<<s<<endl;
	}
	return 0;
}