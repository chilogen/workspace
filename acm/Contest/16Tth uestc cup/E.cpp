#include <bits/stdc++.h>
using namespace std;
int t,n;
char c[200010];
int lastone[200010],lastzero[200010];
int main(){
	int i,k,p0,p1,tans,ans=0;
	cin>>t;
	for(k=0;k<t;k++){
		cin>>n;
		tans=0;
		scanf("%s",c);
		p1=p0=-1;
		for(i=0;i<n;i++){
			if(c[i]=='1'){
				lastone[i]=p1;
				p1=i;
			}
			if(c[i]=='0'){
				lastzero[i]=p0;
				p0=i;
			}
		}
		while(p1<p0&&p0!=-1)p0=lastzero[p0];
		while(p1!=-1&&p0!=-1){
			tans+=2;
			p1=lastone[p1];p0=lastzero[p0];
			while(p1<p0&&p0!=-1)p0=lastzero[p0];
		}
		printf("%.3f\n",float(n-tans));
		//ans+=(n-tans);
	}
	//printf("%.3f\n",(float(ans))/(float(t)));
	return 0;
}