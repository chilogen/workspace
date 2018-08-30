#include <bits/stdc++.h>
using namespace std;
const int maxn=7e7;
int alp[600]={0},m;
int vis[maxn]={0};
void init(){
	char c;
	for(c='a';c<='z';c++)alp[(int)c]=c-'a';
	for(c='A';c<='Z';c++)alp[(int)c]=c-'A';
}
int idx(char c){
	if(c>='a'&&c<='z')return 0;
	return 1;
}
int s[3][3010][2]={0},cnt;

void print(int x){
	int i;
	vector<char>c;
	for(i=0;i<26;i++)
		if(x&(1<<i))c.push_back('A'+i);
	cout<<c.size()<<" ";
	for(i=0;i<(int)c.size();i++)cout<<c[i]<<" ";
	cout<<endl;
}

bool dfs(int x,int stat){
	if(x==cnt){
		print(stat);
		return true;
	}
	int i,j;
	for(i=0;i<3;i++){
		if(s[i][x][1]==-1)continue;
		if(s[i][x][1]&stat)continue;
		j=s[i][x][0]|stat;
		if(dfs(x+1,j))return true;
	}
	return false;
}

int main(){
	init();
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int i,j,k,x,y;
	string str;
	cin>>m;
	x=3*m+1;
	for(i=0;i<3;i++){
		cin>>str;
		k=1;
		for(j=1;j<x;j+=3){
			y=idx(str[j]);
			s[i][k][y]=1<<alp[(int)str[j]];
			y=idx(str[j+1]);
			s[i][k][y]|=1<<alp[(int)str[j+1]];
			if(s[i][k][0]==s[i][k][1])s[i][k][1]=-1;
			k++;
		}
		cnt=k;
	}
	if(!dfs(1,0))cout<<-1<<endl;
	return 0;
}