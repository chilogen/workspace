#include <bits/stdc++.h>
using namespace std;
int n,a[2],ans=0;
vector<int>v;
bool cmp(int x,int y){return x>y;}
int seat(int x){
	int i,j=1,k=0;
	for(i=0;i<x;i++){
		j=!j;
		if(a[j]==0)continue;
		a[j]--;
		k++;
	}
	return k;
}
int main(){
	string s;
	int i,j,k;
	cin>>n>>a[0]>>a[1]>>s;
	for(i=0;i<n;i++){
		if(s[i]=='.'){
			for(j=i;j<n;j++)if(s[j]=='*')break;
			v.push_back(j-i);
			i=j-1;
		}
	}
	k=v.size();i=0;
	while(i<k&&(a[0]||a[1])){
		sort(a,a+2,cmp);
		ans+=seat(v[i]);
		i++;
	}
	cout<<ans<<endl;
	return 0;
}

