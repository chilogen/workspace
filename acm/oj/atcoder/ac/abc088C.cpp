#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL a[4],b[4],c[4][4],i,j,k;
	bool found=false,f;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++)
			cin>>c[i][j];
	}
	for(a[1]=0;a[1]<=100&&!found;a[1]++){
		for(a[2]=0;a[2]<=100&&!found;a[2]++){
			for(a[3]=0;a[3]<=100&&!found;a[3]++){
				b[1]=c[1][1]-a[1];
				b[2]=c[1][2]-a[1];
				b[3]=c[1][3]-a[1];
				f=true;
				for(i=1;i<=3&&f;i++){
					for(j=1;j<=3&&f;j++){
						if(b[j]!=c[i][j]-a[i]){
							f=false;
							break;
						}
					}
				}
				if(f)found=true;

			}
		}
	}
	if(found)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}