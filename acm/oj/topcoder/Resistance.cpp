#include <bits/stdc++.h>
using namespace std;

class Resistance{
public:
	int p,s;
	vector<string>miss;
	vector<int>stat;
	vector<int>valid;
	vector <double> spyProbability(int P, int S, vector <string> missions){
		p=P;s=S;miss=missions;
		vector<double>nil;
		getstats(p,s);
		int i;
		for(i=0;i<(int)stat.size();i++){
			if(ok(stat[i]))valid.push_back(stat[i]);
		}
		if(valid.size()==0)return nil;
		else return getans();
	}
	bool ok(int s){
		int i,j,k;
		char c;
		string ss;
		for(i=0;i<(int)miss.size();i++){
			ss=miss[i];
			c=ss[0];
			if(c=='F'){
				for(j=1;j<(int)ss.length();j++){
					k=p-j;
					if(ss[j]=='1'&&(s&(1<<k)))break;
				}
				if(j==(int)ss.length())return false;
			}
		}
		return true;
	}
	vector<double> getans(){
		double cnt[20]={0},tmp;
		vector<double>ans;
		int i,j;
		for(i=0;i<(int)valid.size();i++){
			for(j=0;j<p;j++){
				if((valid[i]&(1<<j)))cnt[j]=cnt[j]+1;
			}
		}
		cnt[19]=valid.size();
		for(i=0,j=p-1;i<p;i++,j--){
			tmp=cnt[j]/cnt[19];
			ans.push_back(tmp);
		}
		return ans;
	}
	void getstats(int a,int b){
		int i,j,k=1<<a,cnt;
		for(i=0;i<k;i++){
			j=i;cnt=0;
			while(j){
				if(j&1)cnt++;
				j=j>>1;
			}
			if(cnt==b)stat.push_back(i);
		}
	}
	void solve(){
		int p,s;
		string str;
		vector<string>v;
		vector<double>c;
		int i;
		cin>>p>>s;
		for(i=0;i<4;i++){
			cin>>str;
			v.push_back(str);
		}
		c=spyProbability(p,s,v);
		for(i=0;i<(int)c.size();i++){
			cout<<c[i]<<" ";
		}
		cout<<endl;
	}
}a;
int main(){
	a.solve();
	return 0;
}