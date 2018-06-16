#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int o=50;
int a[4],m[60][60];
char b[]={'A','B','C','D'};
bool cmp(char x,char y){
	LL i=x-'A',j=y-'A';
	return a[i]>a[j];
}
bool cmp1(LL x,LL y){
	return x>y;
}
int main(){
	cout<<"50 50\n";
	LL i,j,k,l;
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	sort(b,b+4,cmp);
	sort(a,a+4,cmp1);
	memset(m,-1,sizeof(m));
	for(i=0;i<o&&a[3]>1;i++){
		for(j=i%2;j<o&&a[3]>1;j+=2){
			m[i][j]=3;
			a[3]--;
			if(j+1<o&&m[i][j+1]==-1){
				for(k=0;k<3;k++){
					if(a[k]>0){
						a[k]--;
						m[i][j+1]=k;
						break;
					}
				}
			}
			if(i+1<o&&m[i+1][j]==-1){
				for(k=0;k<3;k++){
					if(a[k]>0){
						a[k]--;
						m[i+1][j]=k;
						break;
					}
				}
			}
		}
	}
	l=i+1;
	for(i+=2;i<o;i+=2){
		for(j=(l+1)%2;j<o;j+=2){
			if(m[i][j]==-1){
				for(k=0;k<3;k++){
					if(a[k]){
						a[k]--;
						m[i][j]=k;
						break;
					}
				}
			}
		}
	}
	for(i=0;i<o;i++){
		for(j=0;j<o;j++){
			if(m[i][j]==-1)cout<<b[3];
			else cout<<b[m[i][j]];
		}
		cout<<endl;
	}
	return 0;
}