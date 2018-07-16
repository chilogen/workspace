#include <bits/stdc++.h>
using namespace std;
int n;
char c[110][110],tmp[110][110];
string cmd;
map<char,int>m;
char a[10][6]{{'|','|','-','-','|','|'},
			  {'\\','\\','\\','\\','/','/'},
			  {'v','^','>','<','^','v'},
			  {'^','v','<','>','v','^'},
			  {'/','/','/','/','\\','\\'},
			  {'<','>','^','v','<','>'},
			  {'o','o','o','o','o','o'},
			  {'>','<','v','^','>','<'},
			  {'x','x','x','x','x','x'},
			  {'-','-','|', '|','-','-'}};
void goleft(){
	memset(tmp,0,sizeof(tmp));
	int i,j,k,l;
	for(i=0,l=n-1;i<n;i++,l--){
		for(j=0,k=0;j<n;j++,k++){
			tmp[i][j]=c[k][l];
			tmp[i][j]=a[m[tmp[i][j]]][0];
		}
	}
	memcpy(c,tmp,sizeof(c));
}
void goright(){
	memset(tmp,0,sizeof(tmp));
	int i,j,k,l;
	for(i=0,l=0;i<n;i++,l++){
		for(j=0,k=n-1;j<n;j++,k--){
			tmp[i][j]=c[k][l];
			tmp[i][j]=a[m[tmp[i][j]]][1];
		}
	}
	memcpy(c,tmp,sizeof(c));
}

void govertical(){
	memset(tmp,0,sizeof(tmp));
	int i,j,k,l;
	for(i=0,k=0;i<n;i++,k++){
		for(j=0,l=n-1;j<n;j++,l--){
			tmp[i][j]=c[k][l];
			tmp[i][j]=a[m[tmp[i][j]]][2];
		}
	}
	memcpy(c,tmp,sizeof(c));
}

void gohorizontal(){
	memset(tmp,0,sizeof(tmp));
	int i,j,k,l;
	for(i=0,k=n-1;i<n;i++,k--){
		for(j=0,l=0;j<n;j++,l++){
			tmp[i][j]=c[k][l];
			tmp[i][j]=a[m[tmp[i][j]]][3];
		}
	}
	memcpy(c,tmp,sizeof(c)); 	
}

void gomain(){
	memset(tmp,0,sizeof(tmp));
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			tmp[i][j]=c[j][i];
			tmp[i][j]=a[m[tmp[i][j]]][4];
		}
	}
	memcpy(c,tmp,sizeof(c));
}

void goantimain(){
	memset(tmp,0,sizeof(tmp));
	int i,j,k,l;
	for(i=0,l=n-1;i<n;i++,l--){
		for(j=0,k=n-1;j<n;j++,k--){
			tmp[i][j]=c[k][l];
			tmp[i][j]=a[m[tmp[i][j]]][5];
		}
	}
	memcpy(c,tmp,sizeof(c));
}

void process(char k){
	switch(k){
		case '<':{
			goleft();
			break;
		}
		case '>':{
			goright();
			break;
		}
		case '|':{
			govertical();
			break;
		}
		case '-':{
			gohorizontal();
			break;
		}
		case '\\':{
			gomain();
			break;
		}
		case '/':{
			goantimain();
			break;
		}
	}
}
int main(){
	int i,l;
	ios::sync_with_stdio(false);
	m['-']=0;m['/']=1;m['<']=2;
	m['>']=3;m['\\']=4;m['^']=5;
	m['o']=6;m['v']=7;m['x']=8;
	m['|']=9;

	while(cin>>n){
		memset(c,0,sizeof(c));
		for(i=0;i<n;i++)cin>>c[i];
		getline(cin,cmd);
		getline(cin,cmd);
		l=cmd.length();
		for(i=0;i<l;i+=2){
			process(cmd[i]);
		}
		for(i=0;i<n;i++)cout<<c[i]<<endl;
	}
	return 0;
}