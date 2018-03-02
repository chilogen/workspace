/*
babaabababba
babab
*/
#include <bits/stdc++.h>
using namespace std;
int *fail;
string patten,s;
void getfail(){
	fail=new int[patten.length()];
	fail[0]=0;
	int i=0,j=1,k=patten.length();
	while(j<k){
		fail[j]=i;
		if(patten[i]==patten[j])	i++;
		else	i=0;
		j++;
	}
}
void find(){
	int i,j,ls=s.length(),lp=patten.length();
	for(i=0,j=0;i<ls;i++){
		while(j!=0&&patten[j]!=s[i])	j=fail[j];
		if(patten[j]==s[i])	j++;
		if(j==lp){
			cout<<i-j+1<<endl;
			return ;
		}
	}
}
int main(){
	cin>>s>>patten;
	getfail();
	find();
	return 0;
}