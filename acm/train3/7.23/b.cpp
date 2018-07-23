#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,ts="happiness";
vector<LL>ans;
int main(){
	size_t pos,i=0;
	cin>>s;
	if(s.length()<9){
		cout<<"YES\n1 2\n";
		return 0;
	}
	while(1){
		pos=s.find(ts.c_str(),pos+i,9);
		if(pos==string::npos)break;
		ans.push_back(pos+1);
		i=1;
	}
	if(ans.size()>2)cout<<"NO\n";
	else{
		cout<<"YES\n";
		if(ans.size()==0){
			swap(s[0],s[1]);
			pos=s.find(ts);
			if(pos==string::npos)cout<<"1 2\n";
			else cout<<"1 3\n";
		}
		if(ans.size()==1){
			cout<<ans[0]<<" "<<ans[0]+1<<endl;
		}
		if(ans.size()==2){
			cout<<ans[0]<<" "<<ans[1]+1<<endl;
		}
	}
	return 0;
}