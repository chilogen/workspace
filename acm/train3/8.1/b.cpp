#include <stdio.h>
#include <string.h>
typedef long long LL;
const LL maxn=2e5;
double ans[200000];
char s[1000];
LL tonum(){
	LL i,j=0,k=1,len=strlen(s);
	for(i=len-1;i>=0;i--){
		if(k>=maxn)return -1;
		j=j+k*(s[i]-'0');
		if(j>=maxn)return -1;
		k*=10;
	}
	return j;
}
int main(){
	LL i;
	double one=1;
	ans[0]=0;
	for(i=1;i<maxn;i++){
		ans[i]=ans[i-1]+one/(i*i);
	}
	while(scanf("%s",s)!=EOF){
		i=tonum();
		if(i>=maxn||i==-1)printf("%.5lf\n",ans[maxn-1]);
		else printf("%.5lf\n",ans[i]);
	}
	return 0;
}