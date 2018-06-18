#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
vector<string>v;
string str2num(LL l,string str){
	string ans="";
	if(str.length()==0)return ans;
	LL i,j=str.length(),k=1,val=0;
	reverse(str.begin(),str.end());
	for(i=0;i<j;i++){
		val+=(k*(LL)(str[i]-'0'));
		k*=10;
	}
	return v[l-val];
}
void split(){
	string tmp="";
	LL i,j,k,len=s.length(),l;
	vector<LL>ind;
	for(i=0,j=0;i<len;i++){
		if(s[i]==';'){
			if(j)ind.push_back(v.size());
			v.push_back(tmp);
			j=0;
			tmp="";
			continue;
		}
		if(s[i]=='#')j=1;
		tmp+=s[i];
	}
	if(tmp.length()!=0){
		if(j)ind.push_back(v.size());
		v.push_back(tmp);
	}
	k=ind.size();
	for(i=0;i<k;i++){
		len=v[ind[i]].length();
		tmp="";
		for(j=len-1;j>=0;j--){
			if(v[ind[i]][j]=='#')break;
			tmp+=v[ind[i]][j];
		}
		reverse(tmp.begin(),tmp.end());
		v[ind[i]]=tmp;
	}
	k=v.size();
	string ttmp;
	for(i=0;i<k;i++){
		len=v[i].length();
		tmp="";j=0;
		while(j<len){
			if(v[i][j]=='@'){
				ttmp="";
				for(l=j+1;l<len;l++){
					if(v[i][l]=='@')break;
					ttmp+=v[i][l];
				}
				ttmp=str2num(i,ttmp);
				j=l+1;
				tmp+=ttmp;
			}
			else{
				tmp+=v[i][j];
				j++;
			}
		}
		v[i]=tmp;
	}
}
int main(){
	LL i,j;
	cin>>s;
	split();
	j=v.size();
	for(i=0;i<j;i++)cout<<v[i]<<endl;
	return 0;
}