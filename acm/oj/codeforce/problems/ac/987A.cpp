#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<string,string>m;
set<string>s;
int n;
int main(){
	m["purple"]="Power";
	m["green"]="Time";
	m["blue"]="Space";
	m["orange"]="Soul";
	m["red"]="Reality";
	m["yellow"]="Mind";
	string all[]={"Power", "Time", "Space", "Soul", "Reality", "Mind"};
	int i;
	cin>>n;
	string str;
	for(i=0;i<n;i++){
		cin>>str;
		s.insert(m[str]);
	}
	cout<<6-s.size()<<endl;
	for(i=0;i<6;i++){
		if(s.count(all[i])==0)cout<<all[i]<<endl;
	}
	return 0;
}