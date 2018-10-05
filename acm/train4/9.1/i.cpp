#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
LL ans=0;

set<LL>s;
hash<string>has;
class longestpalindrime{
private:
	string preprocess(string s){
		string t="$#";
		int len=s.length(),i;
		for(i=0;i<len;i++){
			t+=s[i];
			t+='#';
		}
		return t;
	}
	void add(deque<char>dq){
		string str="";
		LL i,j,k,len;
		char c;
		while(!dq.empty()){
			c=dq.front();dq.pop_front();
			if(c<'1'||c>'9')continue;
			str+=c;
		}
		i=has(str);
		if(s.count(i)!=0)return;
		s.insert(i);
		len=str.length();k=1;
		for(i=len-1;i>=0;i--){
			j=k*(str[i]-'0');
			ans+=j;
			k*=10;
			ans%=mod;
			k%=mod;
		}
	}
public:
	int* getp(string s){
		int i,id,mx,l;
		deque<char>dq;
		s=preprocess(s);
		l=s.length();
		int* p=new int[l];
		id=mx=0;
		for(i=0;i<l;i++){
			if(mx>i){
				p[i]=min(p[2*id-i],mx-i);
				while((LL)dq.size()>2*p[i]-1)
					dq.pop_front();
			}
			else{
				dq.clear();
				dq.push_back(s[i]);
				p[i]=1;
			}

			while(s[i-p[i]]==s[i+p[i]]){
				dq.push_back(s[i+p[i]]);
				dq.push_front(s[i-p[i]]);
				add(dq);
				p[i]++;
			}
			if(mx<i+p[i]){
				mx=i+p[i];
				id=i;
			}
		}

		return p;
	}
};
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	longestpalindrime p;
	p.getp(s);
	cout<<ans<<endl;
	return 0;
}