#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int cnt[maxn]={0},ans=0,n;
int cntpair[maxn]={0};
int main(){
	int i,j;
	while(scanf("%d",&n)!=EOF){
		memset(cnt,0,sizeof(cnt));
		memset(cntpair,0,sizeof(cntpair));
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			cnt[j]++;
		}
		for(i=0;i<maxn;i++){
			j=cnt[i]/2;
			cntpair[i]+=j;
			ans+=j;
			cnt[i]-=(cntpair[i]*2);
		}
		for(i=1;i<maxn-1;i++){
			if(cnt[i]==cnt[i-1]&&cnt[i]==cnt[i+1]&&cnt[i]==1){
				ans++;
				cnt[i]--;
				cnt[i+1]--;
				cnt[i-1]--;
			}
			else if(cnt[i-1]==cnt[i]&&cnt[i]==1){
				if(cntpair[i+1]>0){
					cntpair[i+1]--;
					cnt[i-1]--;
					cnt[i]--;
					cnt[i+1]++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}