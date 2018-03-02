#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	char c[100010];
	int vis[26]={0},t[100010];
	map<int,char>m1;
	map<char,int>m2;
	vector<int>v;
	LL n,k,i,j;
	cin>>n>>k;
	scanf("%s",c);
	for(i=0;i<n;i++){
		vis[c[i]-'a']=1;
	}
	for(i=0,j=0;i<26;i++){
		if(vis[i]){
			v.push_back(i);
		}
	}
	for(i=0;i<v.size();i++){
		m1[i]=v[i]+'a';
		m2[v[i]+'a']=i;
	}
	j=v.size()-1;
	for(i=0;i<k;i++){
		if(i<n) t[i]=m2[c[i]];
		else t[i]=m2[0];
	}
	if(k<=n) t[k-1]++;
	i=k-1;
	while(t[i]==j+1){
		t[i]=0;
		t[i-1]++;
		i--;
	}
	for(i=0;i<k;i++){
		cout<<m1[t[i]];
	}
	cout<<endl;
	return 0;
}