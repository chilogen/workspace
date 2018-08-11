#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >ans;
int n,m;
int main(){
	cin>>n>>m;
	int i,j,k;
	for(i=2;i<=n&&m>0;i++,m--)ans.push_back(make_pair(1,i));
	for(i=2;i<n&&m>0;i++){
		for(j=2;j*i<n&&m>0;j++){
			for(k=(j-1)*i+1;k<j*i&&m>0;k++){
				if(__gcd(i,k)!=1)continue;
				m--;
				ans.push_back(make_pair(i,k));
			}
		}
		for(k=(j-1)*i+1;k<=n&&m>0;k++){
			if(__gcd(i,k)!=1)continue;
			m--;
			ans.push_back(make_pair(i,k));
		}
	}
	if(m)cout<<"Impossible\n";
	else{
		cout<<"Possible\n";
		for(i=0;i<(int)ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}