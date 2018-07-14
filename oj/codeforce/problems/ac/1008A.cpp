#include <bits/stdc++.h>
using namespace std;
int a[256]={0};
char s[200];
int main(){
	a['a']=a['e']=a['i']=a['o']=a['u']=1;
	scanf("%s",s);
	int i,l=strlen(s);
	a[l]='b';
	for(i=0;i<l;i++){
		if(a[(int)s[i]])continue;
		if(s[i]=='n')continue;
		if(a[(int)s[i+1]]!=1)break;
	}
	if(i!=l){
		cout<<"NO\n";
		return 0;
	}
	if(a[(int)s[i-1]]!=1&&s[i-1]!='n'){
		cout<<"NO\n";
	}
	else cout<<"YES\n";
	return 0;
}