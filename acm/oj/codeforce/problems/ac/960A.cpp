#include <bits/stdc++.h>
using namespace std;
int numa,numb,numc;
string s;
void NO(){
	cout<<"NO"<<endl;
	exit(0);
}
int main(){
	numa=numb=numc=0;
	int i,k;
	char j='a';
	cin>>s;
	k=s.length();
	for(i=0;i<k;i++){
		if(s[i]==j+1)j++;
		switch(s[i]){
			case 'a':{
				if(j!='a')NO();
				numa++;
				break;
			}
			case 'b':{
				if(j!='b'||numa==0)NO();
				numb++;
				break;
			}
			case 'c':{
				if(j!='c'||numa==0||numb==0)NO();
				numc++;
				break;
			}
		}
	}
	if((numa!=numc&&numb!=numc)||numa==0||numb==0)NO();
	else cout<<"YES\n";
	return 0;
}