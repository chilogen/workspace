#include <bits/stdc++.h>
using namespace std;

bool query(int x,int y){
	int c;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&c);
	return c;
}
vector<int>v[2];

void solve(){
	int n,i;
	scanf("%d",&n);
	v[1].push_back(1);

	for(i=2;i<=n;i++){
		if(query(1,i))v[1].push_back(i);
		else v[0].push_back(i);
	}


	sort(v[0].begin(),v[0].end(),query);
	sort(v[1].begin(),v[1].end(),query);

	
	if(v[0].size()==0||v[1].size()==0){
		printf("! YES\n");
		for(i=0;i<(int)v[0].size();i++)printf("%d ",v[0][i]);
		for(i=0;i<(int)v[1].size();i++)printf("%d ",v[1][i]);
		cout<<endl;
		fflush(stdout);
	}
	else{
		if(!query(v[0][0],v[1][v[1].size()-1])){
			cout<<"! NO\n";
			cout<<v[0].size()+v[1].size()<<" ";
			for(i=0;i<(int)v[0].size();i++)printf("%d ",v[0][i]);
			for(i=0;i<(int)v[1].size();i++)printf("%d ",v[1][i]);
			fflush(stdout);
		}
		else{
			cout<<"! YES\n";
			for(i=0;i<(int)v[0].size();i++)printf("%d ",v[0][i]);
			for(i=0;i<(int)v[1].size();i++)printf("%d ",v[1][i]);
			cout<<endl;
			fflush(stdout);
		}
	}
}

int main(){
	solve();
	return 0;
}