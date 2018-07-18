#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
map<string,ULL>val;
string s,v1,v2;
ULL mod=(ULL)1<<47;
int main(){
	ULL v;
	while(cin>>s){
		if(s=="def"){
			cin>>v1>>v;
			val[v1]=v;
		}
		else if(s=="sub"){
			cin>>v1>>v2;
			val[v1]=mod+val[v1]-val[v2];
		}
		else if(s=="add"){
			cin>>v1>>v2;
			val[v1]=val[v1]+val[v2];
		}
		else if(s=="mul"){
			cin>>v1>>v2;
			val[v1]=val[v1]*val[v2];
		}
		else if(s=="div"){
			cin>>v1>>v2;
			val[v1]=val[v1]/val[v2];
		}
		else if(s=="mod"){
			cin>>v1>>v2;
			val[v1]=val[v1]%val[v2];
		}
		val[v1]%=mod;
		cout<<v1<<" = "<<val[v1]<<endl;
	}
	return 0;
}