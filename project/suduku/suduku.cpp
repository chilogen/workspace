/*
	using DLX algorithms solve suduku
	by chilogen 2018-03-15
	input format:
		testcase num
		sudu1
		sudu2
		...
	hint:
		every number in sudu should between 1-9
		ohther positions can be any character
	example:
		1
		---24-5--
		-52-76--9
		--'--*8--
		4--31---8
		8976--153
		--1-5-2-4
		53876-9-2
		91643278-
		-745-9316
*/ 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define MaxNode (5000)
#define MaxColume (81*4+1)
#define Maxans	(1000)

vector<LL>v[Maxans];
LL ansnum,ans[Maxans];
char ch[10][10];

vector<LL> encode(LL i,LL j,LL k,LL l){
	vector<LL>tmp;
	tmp.push_back((i-1)*9+k);
	tmp.push_back(81+(j-1)*9+k);
	tmp.push_back(243+(i-1)*9+j);
	i--;j--;
	tmp.push_back(162+(i/3*3+j/3)*9+k);
	return tmp;
}
LL decode(vector<LL>v,LL &i,LL &j,LL &k){
	LL m,n,o,p,q;
	i=v[0]/9+1;
	j=(v[1]-81)/9+1;
	k=v[0]%9;
	if(k==0){
		k=9;
		i--;
		j--;
	}
}

void putans(){
	LL i,j,k,l;
	char c[11][11];
	memset(c,0,sizeof(c));
	for(l=0;l<ansnum;l++){
		decode(v[ans[l]],i,j,k);
		c[i][j]=k+'0';
	}
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++)
			if(c[i][j]<='9'&&c[i][j]>='1')cout<<c[i][j];
			else cout<<" ";
		cout<<endl;
	}
	cout<<endl;
}

class DLX{
private:
	LL col[MaxNode],row[MaxNode];
	LL D[MaxNode],U[MaxNode],L[MaxNode],R[MaxNode];
	LL cnt[MaxColume],n,sz;
	void del(LL c){
		L[R[c]]=L[c];	R[L[c]]=R[c];
		LL i,j;
		for(i=D[c];i!=c;i=D[i]){
			for(j=R[i];j!=i;j=R[j]){
				D[U[j]]=D[j];	U[D[j]]=U[j];
				cnt[col[j]]--;
			}
		}
	}
	void restore(LL c){
		L[R[c]]=c;	R[L[c]]=c;
		LL i,j;
		for(i=D[c];i!=c;i=D[i]){
			for(j=R[i];j!=i;j=R[j]){
				D[U[j]]=j;	U[D[j]]=j;
				cnt[col[j]]++;
			}
		}
	}
public:
	DLX(LL n){
		this->n=n;
		for(sz=0;sz<=n;sz++){
			D[sz]=U[sz]=sz;
			L[sz]=sz-1;	R[sz]=sz+1;
			col[sz]=sz;
		}
		L[0]=sz-1;	R[sz-1]=0;
		memset(cnt,0,sizeof(cnt));
	}
	void addRow(LL r,vector<LL>colume){
		LL first=sz,i,j,c;
		for(i=0;i<colume.size();i++){
			c=colume[i];
			col[sz]=c;	row[sz]=r;
			U[sz]=U[c];	D[sz]=c;
			D[U[c]]=sz;	U[c]=sz;
			L[sz]=sz-1;	R[sz]=sz+1;
			cnt[c]++;	sz++;
		}
		L[first]=sz-1;	R[sz-1]=first;
	}
	//Only find one possible answer,init dep=0;
	bool solve(LL dep){
		if(R[0]==0){
			ansnum=dep;
			putans();
			return true;
		}
		LL c=R[0],i,j;
		for(i=R[0];i!=0;i=R[i])if(cnt[i]<cnt[c])	c=i;

		del(c);
		for(i=D[c];i!=c;i=D[i]){
			ans[dep]=row[i];
			for(j=R[i];j!=i;j=R[j])del(col[j]);
			if(solve(dep+1))return true;
			for(j=R[i];j!=i;j=R[j])restore(col[j]);
		}
		restore(c);
		return false;
	}
	//find all possible answer,init dep=0
	void solveall(LL dep){
		if(R[0]==0){
			ansnum=dep;
			putans();
			return;
		}
		LL c=R[0],i,j;
		for(i=R[0];i!=0;i=R[i])if(cnt[i]<cnt[c])	c=i;

		del(c);
		for(i=D[c];i!=c;i=D[i]){
			ans[dep]=row[i];
			for(j=R[i];j!=i;j=R[j])del(col[j]);
			solveall(dep+1);
			for(j=R[i];j!=i;j=R[j])restore(col[j]);
		}
		restore(c);
	}
}*sudu;

LL tcase;

int main(){
	LL i,j,k,l;
	cin>>tcase;
	while(tcase--){
		sudu=new DLX(81*4);
		for(i=1;i<=9;i++)scanf("%s",ch[i]+1);
		for(i=1,l=0;i<=9;i++){
			for(j=1;j<=9;j++){
				if(ch[i][j]>='1'&&ch[i][j]<='9'){
					v[l]=encode(i,j,ch[i][j]-'0',0);
					sudu->addRow(l,v[l]);
					l++;
					continue;
				}
				for(k=1;k<=9;k++,l++){
					v[l]=encode(i,j,k,1);
					sudu->addRow(l,v[l]);
				}
			}
		}
		cout<<"---------------\n";
		for(i=1;i<=9;i++){
			printf("%s",ch[i]+1);
			if(i==5)cout<<"   ------>";
			cout<<endl;
		}
		cout<<endl;
		sudu->solve(0);
		delete sudu;
	}
	return 0;
}