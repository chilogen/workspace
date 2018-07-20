#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=5010,mod=1e9+7;
LL w[maxn][maxn],n,ans=0,cnt;
LL sum[2][maxn];
LL *p1,*p2;
char s[maxn];
int main(){
	LL i,j;
	cin>>n;
	for(i=1;i<=n;i++)cin>>s[i];
	memset(w,0,sizeof(w));
	w[1][1]=1;cnt=1;
	sum[1][1]=1;
	p1=sum[0];p2=sum[1];
	p1[1]=1;
	for(i=2;i<=n;i++){
		memset(p2,0,sizeof(sum[0]));
		if(s[i-1]=='f'){
			for(j=1;j<=cnt;j++){
				w[i][j+1]=w[i-1][j];
				w[i][j+1]%=mod;
				p2[j+1]=p1[j];
			}
			p2[1]=p2[2];
			cnt=cnt+1;
		}
		else{
			for(j=cnt;j>=1;j--){
				w[i][j]=p1[j];
				p2[j]=p2[j+1]+w[i][j];
				p2[j]%=mod;
			}
		}
		swap(p1,p2);
	}
	for(i=0;i<=n&&s[n]!='f';i++){
		ans+=w[n][i];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}