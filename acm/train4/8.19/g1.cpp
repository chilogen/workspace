#include <bits/stdc++.h>
using namespace std;

const int self=0,jury=1;

int a[4][4],first=jury,r=0,ansx,ansy;

void print(int i,int j){
	cout<<i<<" "<<j<<endl;
	cout.flush();
}

int check(int *b,int flag,int x,int y){
	int i,tv=-1,cnt1=0,cnt2=0;
	for(i=1;i<4;i++){
		if(b[i]==flag)cnt1++;
		if(b[i]==-1){
			cnt2++;
			tv=i;
		}
	}
	if(cnt1==x&&cnt2==y)return tv;
	return -1;
}


bool fun(int flag,int cnt1,int cnt2){
	int i,j,k,b[4];
	for(i=1;i<4;i++){
		for(j=1;j<4;j++)b[j]=a[i][j];
		k=check(b,flag,cnt1,cnt2);
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
		k=check(b,flag,cnt1,cnt2);
		if(k!=-1){
			for(i=1;i<4;i++)if(a[i][j]==-1){
				a[i][j]=self;
				print(i,j);
				return true;
			}
		}
	}
	for(i=1;i<4;i++)b[i]=a[i][i];
	k=check(b,flag,cnt1,cnt2);
	if(k!=-1){
		for(i=1;i<4;i++)if(a[i][i]==-1){
			a[i][j]=self;
			print(i,i);
			return true;
		}
	}
	for(i=1,j=3;i<4;i++,j--)b[i]=a[i][j];
	k=check(b,flag,cnt1,cnt2);
	if(k!=-1){
		for(i=1,j=3;i<4;i++,j--)if(a[i][j]==-1){
			a[i][j]=self;
			print(i,j);
			return true;
		}
	}
	return false;
}


bool win(){
	if(fun(self,2,1))return true;
	return false;
}

bool block(){
	if(fun(jury,2,1))return true;
	return false;
}

void gen(){
	if(block())return;
	if(fun(self,1,2))return;
	int i,j;
	for(i=1;i<4;i++)for(j=1;j<4;j++)if(a[i][j]==-1){
		a[i][j]=self;
		print(i,j);
		return;
	}
}

int tf;

void run(int x,int y){
	a[x][y]=jury;
	if(win())return;
	if(first==jury){
		if(r==1){
			if(a[2][2]==-1){
			 	a[2][2]=self;
			 	print(2,2);
			 	return;
			 }
			 a[1][1]=self;
			 print(1,1);
			 return;
		}
		else if(r==2){
			if(block())return;
			if(tf==1){
				if(a[1][3]==-1){
				a[1][3]=self;
				print(1,3);
				return;
				}
				if(a[3][3]==-1){
					a[3][3]=self;
					print(3,3);
					return;
				}
			}
			else if(tf==0){
				if(a[1][2]==-1){
				a[1][2]=self;
				print(1,2);
				return;
				}
				if(a[2][1]==-1){
					a[2][1]=self;
					print(2,1);
					return;
				}
				if(a[2][3]==-1){
					a[2][3]=self;
					print(2,3);
					return;
				}
				if(a[3][2]==-1){
					a[3][2]=self;
					print(3,2);
					return;
				}
			}
			return;
		}
	}
	else if(block())return;
	gen();
}

int main(){
	memset(a,-1,sizeof(a));
	char ch;
	string s;
	int x,y;
	cin>>ch;
	if(ch=='X'){
		a[2][2]=self;
		print(2,2);
		first=self;
	}
	while(cin>>s){
		if(s=="WIN"||s=="DRAW"||s=="LOSE")break;
		x=s[0]-'0';cin>>y;
		r++;
		if(r==1){
			if(x==2&&y==2)tf=0;
			else tf=1;
		}
		run(x,y);
	}
}