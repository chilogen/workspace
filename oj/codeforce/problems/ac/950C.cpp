#include <bits/stdc++.h>
using namespace std;
string s;
queue<int>q[2];
vector<int>v[200010];
int main(){
	cin>>s;
	int i,j,k,l,len=s.length();
	for(i=l=0;i<len;i++){
		if(s[i]=='0'){
			if(!q[1].empty()){
				j=q[1].front();q[1].pop();
				v[j].push_back(i+1);
				q[0].push(j);
			}
			else{
				l++;
				v[l].push_back(i+1);
				q[0].push(l);
			}
		}
		else{
			if(!q[0].empty()){
				j=q[0].front();q[0].pop();
				v[j].push_back(i+1);
				q[1].push(j);
			}
			else{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	if(!q[1].empty()){
		cout<<-1<<endl;
		return 0;
	}
	cout<<l<<endl;
	for(i=1,j=l+1;i<j;i++){
		cout<<v[i].size()<<" ";
		for(k=0;k<v[i].size();k++)cout<<v[i][k]<<" ";
		cout<<endl;
	}
	return 0;
}