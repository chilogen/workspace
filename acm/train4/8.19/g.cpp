#include <bits/stdc++.h>
using namespace std;
const int self=0,jury=1;
int a[4][4];
int x,y;
string s;


void print(int i,int j){
	cout<<i<<" "<<j<<endl;
	cout.flush();
}

int check(int *b,int flag){
	int i,tv=-1,cnt1=0,cnt2=0;
	for(i=0;i<4;i++){
		if(b[i]==flag)cnt1++;
		if(b[i]==-1){
			cnt2++;
			tv=i;
		}
	}
	if(cnt1==2&&cnt2==1)return tv;
	return -1;
}

bool fun(int flag){
	int i,j,k;
	int b[4];
	for(i=1;i<4;i++){
		for(j=1;j<4;j++)b[j]=a[i][j];
		k=check(b,flag);
		if(k!=-1){
			for(j=1;j<4;j++)if(a[i][j]==-1){
				a[i][j]=self;
				print(i,j);
				return true;
			}
		}
	}
	for(j=1;j<4;j++){
		for(i=1;i<4;i++)b[i]=a[i][j];
		k=check(b,flag);
		if(k!=-1){
			for(i=1;i<4;i++)if(a[i][j]==-1){
				a[i][j]=self;
				print(i,j);
				return true;
			}
		}
	}
	for(i=1;i<4;i++)b[i]=a[i][i];
	k=check(b,flag);
	if(k!=-1){
		for(i=1;i<4;i++)if(a[i][i]==-1){
			a[i][j]=self;
			print(i,i);
			return true;
		}
	}
	for(i=1,j=3;i<4;i++,j--)b[i]=a[i][j];
	k=check(b,flag);
	if(k!=-1){
		for(i=1,j=3;i<4;i++,j--)if(a[i][j]==-1){
			a[i][j]=self;
			print(i,j);
			return true;
		}
	}
	return false;
}

int check1(int *b){
	int i,tv=-1,cnt1=0,cnt2=0;
	for(i=0;i<4;i++){
		if(b[i]==self)cnt1++;
		if(b[i]==-1){
			cnt2++;
			tv=i;
		}
	}
	if(cnt1==1&&cnt2==2)return tv;
	return -1;
}

bool fun1(){
	int i,j,k;
	int b[4];
	for(i=1;i<4;i++){
		for(j=1;j<4;j++)b[j]=a[i][j];
		k=check1(b);
		if(k!=-1){
			for(j=1;j<4;j++)if(a[i][j]==-1){
				a[i][j]=self;
				print(i,j);
				return true;
			}
		}
	}
	for(j=1;j<4;j++){
		for(i=1;i<4;i++)b[i]=a[i][j];
		k=check1(b);
		if(k!=-1){
			for(i=1;i<4;i++)if(a[i][j]==-1){
				a[i][j]=self;
				print(i,j);
				return true;
			}
		}
	}
	for(i=1;i<4;i++)b[i]=a[i][i];
	k=check1(b);
	if(k!=-1){
		for(i=1;i<4;i++)if(a[i][i]==-1){
			a[i][j]=self;
			print(i,i);
			return true;
		}
	}
	for(i=1,j=3;i<4;i++,j--)b[i]=a[i][j];
	k=check1(b);
	if(k!=-1){
		for(i=1,j=3;i<4;i++,j--)if(a[i][j]==-1){
			a[i][j]=self;
			print(i,j);
			return true;
		}
	}
	return false;
}

void run(){
	a[x][y]=jury;
	if(fun(self))return;
	if(fun(jury))return;
	if(fun1())return;
	int i,j;
	if(a[2][2]==-1){
		a[2][2]=self;
		print(2,2);
		return ;
	}
	for(i=1;i<4;i++)for(j=1;j<4;j++)if(a[i][j]==-1){
		a[i][j]=self;
		print(i,j);
		return;
	}
}

int main(){
	memset(a,-1,sizeof(a));
	char ch;
	cin>>ch;
	if(ch=='X'){
		a[2][2]=self;
		print(2,2);
	}
	while(cin>>s){
		if(s=="WIN"||s=="DRAW"||s=="LOSE")break;
		x=s[0]-'0';cin>>y;
		run();
	}
	return 0;
}