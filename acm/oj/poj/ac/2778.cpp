#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
typedef long long LL;
const LL mod=100000,maxn=101,sigma=4;
typedef long long MATRIX[maxn][maxn];  
      
MATRIX mat, mat1, mat2;  
long long (*m1)[maxn], (*m2)[maxn];
LL n,m;
LL ch[maxn][sigma]={0},fail[maxn]={0},flag[maxn]={0},sz=0;
string str;
int idx(char c){
	switch(c){
		case 'A':return 0;
		case 'T':return 1;
		case 'C':return 2;
		case 'G':return 3;
	}
	return 0;
}

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

    void matrixMult(MATRIX t1, MATRIX t2, MATRIX res)  
    {  
        for (int i = 0; i <=sz; i++)  
            for (int j = 0; j <=sz; j++)  
            {  
                res[i][j] = 0;  
                for (int k = 0; k <=sz; k++)  
                {  
                    res[i][j] += t1[i][k] * t2[k][j];  
                }  
                res[i][j] %= 100000;  
            }  
    }  
      
    /* 
        递归二分计算矩阵的p次幂，结果存在m2[][]中 
    */  
    void matrixPower(int p)  
    {  
        if (p == 1)  
        {  
            for (int i = 0; i <=sz; i++)  
                for (int j = 0; j <=sz; j++)  
                    m2[i][j] = mat[i][j];  
            return;  
        }  
      
        matrixPower(p/2);          //计算矩阵的p/2次幂，结果存在m2[][]  
        matrixMult(m2, m2, m1);    //计算矩阵m2的平方，结果存在m1[][]  
      
        if (p % 2)                 //如果p为奇数，则再计算矩阵m1乘以原矩阵mat[][]，结果存在m2[][]  
            matrixMult(m1, mat, m2);  
        else  
            swap(m1, m2);  
    } 


void insert(){
	LL i,j,k=0,l=str.length();
	for(i=0;i<l;i++){
		j=idx(str[i]);
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
	LL i,j,k;/*
	for(i=0;i<maxn;i++){
		if(flag[i])continue;
		for(j=0;j<sigma;j++){
			if(ch[i][j]&&flag[ch[i][j]])continue;
			if(ch[i][j]&&!flag[ch[i][j]])mat[i][ch[i][j]]++;
			else{
				k=fail[i];
				while(k&&!ch[k][j])k=fail[k];
				mat[i][ch[k][j]]++;
			}
		}
	}*/
	for(i=0;i<=sz;i++)for(j=0;j<sigma;j++){
		if(!flag[i]&&!flag[ch[i][j]])mat[i][ch[i][j]]++;
	}
}
int main(){
	LL i,l=0;
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(i=0;i<m;i++){
		cin>>str;
		insert();
	}
	getfail();
	getmatrix();
	m1 = mat1;  
	m2 = mat2; 
	//mpow(n);
	matrixPower(n); 
	for(i=0;i<=sz;i++)l+=m2[0][i];
	cout<<l%mod<<endl;
	return 0;
}