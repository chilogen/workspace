#include <bits/stdc++.h>
using namespace std;
#define Maxnode ((LL)1e6)
typedef long long LL;

class DLX{
private:
	LL n,sz;											//n-->the colume size;	sz-->node index
	LL R[Maxnode],L[Maxnode],D[Maxnode],U[Maxnode];		//the pointer of Right(R),Left(L),Down(D) and Up(U)
	LL cnt[Maxnode>>3];									//the number of '1' in every colume
	LL col[Maxnode],row[Maxnode];						//the colume index and row index of each node
	LL ans[Maxnode>>3],anslen;							//store which set will be choosed


	/*
		@param:
			r : the index number of the colume
			colume : store the index that the value of the position is '1'
	*/
	void AddRow(LL r,vector<LL>colume){
		LL first=sz,c,i;
		for(i=0;i<colume.size();i++){
			c=colume[i];
			U[sz]=U[c];	D[sz]=c;
			D[U[c]]=sz;	U[c]=sz;
			cnt[c]++;
			L[sz]=sz-1;	R[sz]=sz+1;
			col[sz]=c;	row[sz]=r;
			sz++;
		}
		L[first]=sz-1;	R[sz-1]=first;
	}

	/*
		@param:
			c : the colume index will delete
	*/
	void del(LL c){
		LL i,j;
		R[L[c]]=R[c];	L[R[c]]=L[c];
		for(i=D[c];i!=c;i=D[i]){
			for(j=R[i];j!=i;j=R[j]){
				D[U[j]]=D[j];
				U[D[j]]=U[j];
				cnt[col[j]]--;
			}
		}
	}

	/*
		@param:
			c : the colume index will restore
	*/
	void restore(LL c){
		LL i,j;
		R[L[c]]=c;	L[R[c]]=c;
		for(i=D[c];i!=c;i=D[i]){
			for(j=R[i];j!=i;j=R[j]){
				U[D[j]]=j;
				D[U[j]]=j;
				cnt[col[j]]++;
			}
		}
	}
	/*
		@param:
			dep : the depth of recursive
	*/
	bool getans(LL dep){
		if(R[0]==0){
			anslen=dep;
			return true;
		}
		LL c=R[0],i,j;
		for(i=R[0];i!=0;i=R[i])	
			if(cnt[i]>cnt[c])	c=i;

		del(c);
		for(i=D[c];i!=c;i=D[i]){
			ans[dep]=row[i];
			for(j=R[i];j!=i;j=R[j])	del(col[j]);
			if(getans(dep+1))	return true;
			for(j=R[i];j!=i;j=R[j])	
				restore(col[j]);
		}
		restore(c);
		return false;
	}

	void putans(){
		LL i;
		cout<<"choose set below:\n";
		for(i=0;i<anslen;i++)cout<<"set "<<ans[i]<<endl;
	}

public:
	/*
		@param:
			n : the colume size
	*/
	DLX(LL n){
		this->n=n;	memset(cnt,0,sizeof(cnt));
		for(sz=0;sz<=n;sz++){
			R[sz]=sz+1;	L[sz]=sz-1;
			D[sz]=sz;	U[sz]=sz;
		}
		L[0]=sz-1;	R[sz-1]=0;
	}

	void solve(){
		LL i,j,k,l,m;
		vector<LL>v;
		cin>>m;
		//cout<<"get each set\n";
		//cout<<"(sizeof set) (set):\n";
		for(i=1;i<=m;i++){
			cin>>k;
			v.clear();
			for(j=0;j<k;j++){
				cin>>l;
				v.push_back(l);
			}
			AddRow(i,v);
		}
		if(!getans(0)){
			cout<<"Do not have answer\n";
			return;
		}
		putans();
	}
};
int main(){
	LL i;
	cin>>i;
	DLX *m=new DLX(i);
	m->solve();
	return 0;
}