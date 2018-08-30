#include <iostream>
using namespace std;
int a[3][3];

void run(int m,int d){
	int x,y,b[2][3],i,j,k,l;
	switch(m){
		case 1:{
			x=y=0;
			break;
		}
		case 2:{
			x=0;y=1;
			break;
		}
		case 3:{
			x=1;y=0;
			break;
		}
		case 4:{
			x=y=1;
			break;
		}
	}
	for(i=x,k=0;i<x+2;i++,k++)for(j=y,l=0;j<y+2;j++,l++){
		b[k][l]=a[i][j];
	}
	if(d==0){
		i=b[0][0];
		b[0][0]=b[1][0];
		b[1][0]=b[1][1];
		b[1][1]=b[0][1];
		b[0][1]=i;
	}
	if(d==1){
		i=b[0][0];
		b[0][0]=b[0][1];
		b[0][1]=b[1][1];
		b[1][1]=b[1][0];
		b[1][0]=i;
	}
	for(i=x,k=0;i<x+2;i++,k++)for(j=y,l=0;j<y+2;j++,l++){
		a[i][j]=b[k][l];
	}
}

void solve(){
	int n,i,j,k;
	char c;
	cin>>n;
	for(i=0;i<3;i++)for(j=0;j<3;j++){
		cin>>c;
		a[i][j]=c-'0';
	}
	for(i=0;i<n;i++){
		cin>>c;
		j=c-'0';
		cin>>c;
		if(c=='C')k=0;
		else k=1;
		run(j,k);
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)cout<<a[i][j];
		cout<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}