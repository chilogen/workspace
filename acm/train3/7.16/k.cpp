#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s[2],End=".";
vector<string>v[2];
void split(int x){
	string tmp="";
	int len=s[x].length(),i;
	v[x].clear();
	for(i=0;i<len;i++){
		if(s[x][i]==';'){
			v[x].push_back(tmp);
			tmp="";
			continue;
		}
		if(s[x][i]=='"'){
			v[x].push_back(tmp);
			tmp="";
			tmp+=s[x][i];
			for(i=i+1;i<len;i++){
				if(s[x][i]=='"'){
					v[x].push_back(tmp);
					tmp="";
					break;
				}
				tmp+=s[x][i];
			}
			continue;
		}
		tmp+=s[x][i];
	}
	v[x].push_back(tmp);
}
int main(){
	int i,j,l;
	while(1){
		cin>>s[0];
		if(s[0]==End)break;
		cin>>s[1];
		split(0);
		split(1);
		if(v[0].size()!=v[1].size()){
			cout<<"DIFFERENT\n";
			continue;
		}
		l=0;j=v[0].size();
		for(i=0;i<j;i++){
			if(v[0][i]==v[1][i])continue;
			l++;
			if(v[0][i][0]!='"')l++;
			if(l>1)break;
		}
		if(l==0)cout<<"IDENTICAL\n";
		if(l==1)cout<<"CLOSE\n";
		if(l>1)cout<<"DIFFERENT\n";
	}
	return 0;
}