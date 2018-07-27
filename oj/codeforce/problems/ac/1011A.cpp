#include <bits/stdc++.h>
using namespace std;
int n,k;
int vis[26]={0};
int main(){
	int i,j,l;
	string s;
	cin>>n>>k>>s;
	for(i=0;i<n;i++)vis[s[i]-'a']=1;
	for(i=j=l=0;i<k;i++){
		while(!vis[l]&&l<26)l++;
		if(l==26){
			cout<<-1<<endl;
			return 0;
		}
		j+=(l+1);vis[l+1]=0;
		l++;
	}
	cout<<j<<endl;
	return 0;
}