#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s[10],ts;
LL n,cnt;
vector<string>ans;
string getstr(LL x){
	string bs="";
	LL i;
	for(i=0;i<(LL)ts.length();i++){
		if(x&(1<<i))bs+=ts[i];
	}
	return bs;
}
string getstr1(string s,LL i){
	LL k;
	string bs="";
	for(k=i;k<(LL)s.length();k++)bs+=s[k];
	for(k=0;k<i;k++)bs+=s[k];
	return bs;
}
bool ok(string a,string b){
	LL i,j;
	for(i=j=0;i<(LL)a.length()&&j<(LL)b.length();j++){
		if(a[i]==b[j])i++;
	}
	return i==(LL)a.length();
}
void push(LL x){
	string bs1=getstr(x),bs2;
	LL i;
	for(i=0;i<(LL)bs1.length();i++){
		bs2=getstr1(bs1,i);
		ans.push_back(bs2);
	}
}

bool cmp(string a,string b){
	if(a.length()==b.length())return a<b;
	return a.length()>b.length();
}

bool solve(){
	ans.clear();
	LL i,j,k,l;
	ts="12345678910";
	string bs1,bs2;
	if(!(cin>>n))return false;
	for(i=0;i<n;i++){
		cin>>s[i];
		if(s[i].length()<ts.length())ts=s[i];
	}
	l=ts.length();
	for(i=1;i<(2<<l);i++){
		bs1=getstr(i);
		for(j=0;j<n;j++){
			for(k=0;k<(LL)s[j].length();k++){
				bs2=getstr1(s[j],k);
				if(ok(bs1,bs2))break;
			}
			if(k==(LL)s[j].length())break;
		}
		if(j!=n)continue;
		push(i);
	}
	if(ans.size()==0){
		cout<<0<<endl;
		return true;
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans[0]<<endl;
	return true;
}

int main(){
	while(solve());
	return 0;
}