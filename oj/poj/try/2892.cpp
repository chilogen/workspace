//#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <map>
#include <stack>
using namespace std;
int main(){
	map<int,int>s;
	map<int,int>::iterator a,b;
	stack<int>st;
	int n,m,i,j,k;
	char c;
	cin>>n>>m;
	s[0]=1;
	s[n+1]=1;
	for(i=0;i<m;i++){
		cin>>c;
		if(c=='D'){
			cin>>j;
			s[j]=1;
			//s.insert(j);
			st.push(j);
		}
		else if(c=='Q'){
			cin>>j;
			a=s.lower_bound(j);
			if(a->first==j){
				cout<<0<<endl;
				continue;
			}
			a--;
			b=s.upper_bound(j);
			cout<<b->first-a->first-1<<endl;
		}
		else{
			s.erase(st.top());
			st.pop();
		}
	}
	return 0;
}