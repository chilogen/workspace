#include <bits/stdc++.h>
using namespace std;
map<string,char>m;
int main(){
	m[".-"] ='A';m["-..."] ='B';
	m["-.-."] ='C';m["-.."] ='D';
	m["."] ='E';m["..-."] ='F';
	m["--."] ='G';m["...."] ='H';
	m[".."] ='I';m[".---"] ='J';
	m["-.-"] ='K';m[".-.."] ='L';
	m["--"] ='M';m["-."] ='N';
	m["---"] ='O';m[".--."] ='P';
	m["--.-"] ='Q';m[".-."] ='R';
	m["..."] ='S';m["-"] ='T';
	m["..-"] ='U';m["...-"] ='V';
	m[".--"] ='W';m["-..-"] ='X';
	m["-.--"] ='Y';m["--.."] ='Z';
	string str,ans,tmp;
	int i,l;
	while(cin>>str){
		l=str.length();
		ans="";tmp="";
		for(i=0;i<l;i++){
			if(str[i]=='/'){
				if(i+1<l&&str[i+1]=='/'){
					ans+=m[tmp];
					tmp="";
					ans+=" ";
					i++;
				}
				else{
					ans+=m[tmp];
					tmp="";
				}
			}
			else tmp+=str[i];
		}
		ans+=m[tmp];
		cout<<ans<<endl;
	}
	return 0;
}