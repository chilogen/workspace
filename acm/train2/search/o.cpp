#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7,maxn=101,sigma=4;
LL mat[maxn][maxn],mat1[maxn][maxn],mat2[maxn][maxn];  
LL (*m1)[maxn],(*m2)[maxn];
LL n,m;
LL ch[maxn][sigma]={0},fail[maxn]={0},flag[maxn]={0},sz=0;
string str;

/*
void mul(LL a[maxn][maxn],LL b[maxn][maxn]){
	LL i,j,k,l;
	memset(tmat1,0,sizeof(tmat1));
	for(i=0;i<maxn;i++)for(j=0;j<maxn;j++){
		for(k=0;k<maxn;k++){
			l=a[i][k]*b[k][j];
			l%=mod;
			tmat1[i][j]+=l;
			tmat1[i][j]%=mod;
		}
	}
	memcpy(a,tmat1,sizeof(tmat1));
}
void mpow(LL x){
	LL i;
	for(i=0;i<maxn;i++)ans[i][i]=1;
	while(x){
		if(x&1)	mul(ans,mat);
		x>>=1;
		mul(mat,mat);
	}
}*/

void mul(LL (*t1)[maxn],LL (*t2)[maxn],LL (*res)[maxn]){ 
	LL i,j,k;
	memset(res,0,sizeof(mat));
	for(i=0;i<=sz;i++)for(j=0;j<=sz;j++){  
          for(k=0;k<=sz;k++)res[i][j]+=t1[i][k]*t2[k][j];
          res[i][j]%=mod;
    }
}

void mpow(LL p){  
	LL i,j;
    if (p == 1){  
        for (i=0;i<=sz;i++)for(j=0;j<=sz;j++)
			m2[i][j]=mat[i][j];  
		return;  
	}
	mpow(p/2);
	mul(m2,m2,m1);
    if(p%2)mul(m1,mat,m2);
    else swap(m1,m2);  
} 


void insert(){
	LL i,j,k=0,l=str.length();
	for(i=0;i<l;i++){
		j=str[i]-'0';
		if(!ch[k][j])ch[k][j]=++sz;
		k=ch[k][j];
	}
	flag[k]=1;
}
void getfail(){
	LL i,j,k;
	queue<LL>bfs;
	for(i=0;i<sigma;i++)if(ch[0][i])bfs.push(ch[0][i]);
	while(!bfs.empty()){
		k=bfs.front();bfs.pop();
		if(flag[fail[k]])flag[k]=1;
		for(i=0;i<sigma;i++){
			if(!ch[k][i]){ch[k][i]=ch[fail[k]][i];continue;}
			bfs.push(ch[k][i]);
			j=fail[k];
			while(j&&!ch[j][i])j=fail[j];
			fail[ch[k][i]]=ch[j][i];
		}
	}
}
void getmatrix(){
	LL i,j;
	for(i=0;i<=sz;i++)for(j=0;j<sigma;j++){
		if(!flag[i]&&!flag[ch[i][j]])mat[i][ch[i][j]]++;
	}
}
int main(){
	LL i,l=0;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>str;
		insert();
	}
	getfail();
	getmatrix();
	m1=mat1;  
	m2=mat2; 
	mpow(n);
	for(i=0;i<=sz;i++)l+=m2[0][i];
	cout<<l%mod<<endl;
	return 0;
}